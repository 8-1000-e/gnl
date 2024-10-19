/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/19 21:15:38 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memcpy(char *dest, char *src)
{
	char	*clone;

	clone = dest;
	while (*src && *src != '\n')
		*dest++ = *src++;
	if (*src == '\n')
		*dest++ = *src++;
	*dest = '\0';
	return (clone);
}

char *invalid_empty_read(char *buf, int b, char *line, char *save_old_line)
{
	if (save_old_line)
			free(save_old_line);
	if (b == -1)
	{
		if (line)
			free(line);
		return (NULL);	
	}
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	return (line);
}

char *get_following_line(int fd, char *buf, char *save_old_line, char *line)
{
	int	b;

	b = 0;
	while (1)
		{
			if (save_old_line)
			{
				line = ft_strjoin(save_old_line, 0);
				save_old_line = NULL;
			}
			b = read(fd, buf, BUFFER_SIZE);
			if (b == -1)
				return (invalid_empty_read(buf, b, line, save_old_line));
			if (!b && !next_line_in_buf(buf))
				return (invalid_empty_read(buf, b, line, save_old_line));
			if (!save_old_line)
				line = ft_strjoin(line, buf);
			ft_memset(buf, 0, BUFFER_SIZE + 1);
			if (!line)
				return (NULL);
			if (next_line_in_buf(line))
				return (cut_next_line(line, buf));
		}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line;
	char		*save_old_line;
		
		line = NULL;
		save_old_line = NULL;
		if (buf[0])
		{
			save_old_line = malloc(BUFFER_SIZE + 1);
			if (!save_old_line)
				return (NULL);
			ft_memcpy(save_old_line, buf);
		}
		return (get_following_line(fd, buf, save_old_line, line));
}

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *s;
	int	i;

	i = 0;
	int fd = open("test.txt", O_RDONLY);

	s = get_next_line(fd);
	while (s)
	{
		printf("%s|, %d", s, i);
		free(s);
		i++;
		s = get_next_line(fd);
	}
	close(fd);
}