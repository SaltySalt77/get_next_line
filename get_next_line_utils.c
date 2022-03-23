/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyna <hyns@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 23:41:43 by hyna              #+#    #+#             */
/*   Updated: 2022/03/11 18:26:07 by hyna             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char	*s, int c)
{
	char	tmp;

	if (!s)
		return (NULL);
	tmp = (char)c;
	while ((*s) && (*s != tmp))
		s++;
	if (*s == tmp)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char	*s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*free_str(char	*s)
{
	free(s);
	return (NULL);
}
