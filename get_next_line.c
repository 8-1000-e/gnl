/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/18 18:01:04 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memcpy(char *dest, char *src)
{
	char	*clone;

	clone = dest;
	while (*src && *src != '\n')
		src++;
	while (*++src)
		*dest++ = *src;
	*dest = '\0';
	return (clone);
}

char *invalid_empty_read(int b, char *line, char *save_old_line)
{
	if (save_old_line)
			free(save_old_line);
	if (b == -1)
	{
		if (line)
			free(line);
		return (NULL);	
	}
	return (line);
}
char *get_following_line(int fd, char *buf, char *save_old_line, char *line)
{
	int	b;

	b = 0;
	while (1)
		{
			b = read(fd, buf, BUFFER_SIZE);
			if (b == -1)
				return (invalid_empty_read(b, line, save_old_line));
			if (!b)
				return (invalid_empty_read(b, line, save_old_line));
			if (save_old_line)
			{
				line = ft_strjoin(save_old_line, buf);
				save_old_line = NULL;
			}
			else
				line = ft_strjoin(line, buf);
			if (!line)
				return (NULL);
			if (next_line_in_buf(line))
				return (cut_next_line(line));
		}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE];
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
// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int	main()
// {
// 	char *s;

// 	int	fd = open("test.txt", O_RDONLY); 
	
// 	s = get_next_line(fd);
// 	while (s)
// 	{
// 		printf("%s", s);
// 		s = get_next_line(fd);
// 	}

// }