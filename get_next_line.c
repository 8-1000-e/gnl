/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/21 06:27:01 by edubois-         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*save_str;
	char 	*s1_tmp;

	s1_tmp = s1;
	str = malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	save_str = str;
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	if (s1_tmp)
		free(s1_tmp);
	return (save_str);
}

char	*cut_at_next_line(char *line)
{
	while (line && *line && *line != '\n')
			line++;
	if (line && *line)
		return (++line);
	return (NULL);
	
}

void delete_old_line(char *line, char *buf)
{
	line = cut_at_next_line(line);
	while (line && *line)
	{
			*buf++ = *line;
			*line++ = '\0';
	}
	*buf = '\0';
}

int	ft_strcmp(char *s1, char *s2)
{
	char *save_s1;
	
	save_s1 = s1;
	while (s1 && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && !*s1 && !*s2)
	{	
		free(save_s1);
		return (1);
	}
	return (0);
}

char	*get_following_line(int	fd, char *buf, char *line)
{
	int	b;

	b = 1;
	while (b > 0)
	{
		if (cut_at_next_line(line))
			break ;
		ft_memset(buf, 0, BUFFER_SIZE);
		b = read(fd, buf, BUFFER_SIZE);
		line = ft_strjoin(line, buf);
		if (!line || ft_strcmp(line, ""))
			return (NULL);
	}
	if (b == -1)
	{
		free(line);
		return (NULL);
	}
	if (!b)
	{
		buf = NULL;
		return(line);
	}
	delete_old_line(line, buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1] = {0};
	char		*line;
		
		line = NULL;
		if (ft_strlen(buf))
		{
			line = ft_strjoin(line, buf);
			if (!line)
				return (NULL);
		}
		return (get_following_line(fd, buf, line));
}

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
// 
// int main(int argc, char **argv)
// {	
	// (void) argc;
	// char *s;
	// int fd = open(argv[1], O_RDONLY);
	// s = get_next_line(fd);
	// while (s)
	// {
		// printf("%s ", s);
		// free(s);
		// s = get_next_line(fd);
	// }
	// close(fd);
// }