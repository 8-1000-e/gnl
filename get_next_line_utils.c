/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:37:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/19 22:13:42 by edubois-         ###   ########.fr       */
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
	while (s2 && *s2)
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
d		return (0);
	return (1);
}

char	*cut_next_line(char *line, char *buf)
{
	char	*save_buf;
	char	*save_new;
	
	save_buf = line;
	while (*line && *line != '\n')
		line++;
	save_new = line;
	while (*++line)
		*buf++ = *line;
	while (*buf)
		*buf++ = '\0';
	line = save_new;
	if (*line && *++line)
	{
		while (*line)
			*line = '\0';
	}
	
	return (save_buf);
}
void	*ft_memset(void *s, int c, size_t n)
{
	void	*clone;

	if (!s)
		return (NULL);
	clone = s;
	while (n--)
		*(unsigned char *)s++ = c;
	return (clone);
}