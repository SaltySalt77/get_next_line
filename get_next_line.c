/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyns@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:50:17 by hyna              #+#    #+#             */
/*   Updated: 2022/03/03 06:37:05 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *mv_backup(char *backup)
{
	char *result;
	int i;
	int j;

	i = 0;
	while (backup[i] && (backup[i] != '\n'))
		i++;
	if (backup[i] == 0)
		return (NULL);
	j = i;
	while (backup[i])
		i++;
	result = malloc(i - j);
	if (!result)
		return (NULL);
	i = 0;
	j++;
	while (backup[j])
		result[i++] = backup[j++];
	result[i] = 0;
	free(backup);
	return (result);
}

static char *make_result(char *backup)
{
	char *result;
	int i;
	int j;

	i = 0;
	j = 0;
	printf("test : %s\n--------\n", backup);
	while (backup[i] && (backup[i] != '\n'))
		i++;
	if (!(backup[i]))
		return ((char *)backup);
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	while (j <= i)
	{
		result[j] = backup[j];
		printf("result[%d] : %c / backup[%d] : %c\n", j, result[j], j, backup[j]);
		j++;
	}
	result[j] = 0;
	return (result);
}

static char *make_backup(char *s1, char *s2)
{
	char *result;
	size_t s1_len;
	size_t s2_len;
	size_t i;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (!result)
		return (0);
	i = -1;
	while (++i < s1_len)
		result[i] = s1[i];
	i = 0;
	while (i < s2_len)
		result[s1_len++] = s2[i++];
	result[s1_len] = 0;
	if (s1)
		free(s1);
	return (result);
}

static char *read_files(int fd, char *backup)
{
	ssize_t read_len;
	char buf[BUFFER_SIZE + 1];

	buf[BUFFER_SIZE] = 0;
	while (!ft_strchr(backup, '\n'))
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		if (read_len == -1)
			return (NULL);
		else if (read_len == 0)
		{
			if (!backup)
				return (NULL);
			return (backup);
		}
		buf[read_len] = 0;
		printf("buf : %s\n--------\n", buf);
		backup = make_backup(backup, buf);
		printf("backup : %s\n-------\n", backup);
	}
	return (backup);
}

char *get_next_line(int fd)
{
	static char *backup;
	char *result;
	char *tmp;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	tmp = read_files(fd, backup);
	if (!tmp)
		return (NULL);
	printf("---%s---\n", tmp);
	result = make_result(tmp);
	if (!result)
		return (NULL);
	backup = mv_backup(tmp);
	return (result);
}
