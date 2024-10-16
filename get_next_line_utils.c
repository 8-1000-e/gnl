/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:37:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/16 17:16:23 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	c;

	c = 0;
	if (!s)
		return (0);
	while (*s++)
		c++;
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*save_str;
    char    *save_s1;
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
	{
        free(s1);
        return (NULL);
    }
    save_str = str;
    save_s1 = s1;
	if (s1)
	{
		while (*s1)
			*str++ = *s1++;
	}
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
    if (save_s1)
        free(save_s1);
    return (save_str);
}

int	next_line_in_buf(char *buf)
{
	if (!buf)
		return (0);
	while (*buf && *buf != '\n')
		buf++;
	if (!*buf)
		return (0);
	return (1);
}

char	*cut_next_line(char *buf)
{
	char	*save_buf;

	save_buf = buf;
	while (*buf && *buf != '\n')
		buf++;
	if (*buf && *++buf)
	{
		while (*buf)
			*buf = '\0';
	}
	return (save_buf);
}
