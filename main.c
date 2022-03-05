#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
	int fd;
	int n;
	char *print;

	n = 0;
	fd = open("test1.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	while (n < 10)
	{
		print = get_next_line(fd);
		if (!print)
			break;
		printf("%d : %s", print);
		free(print);
		n++;
	}
	close(fd);
	return (0);
}
