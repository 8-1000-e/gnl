/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/16 17:18:05 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE];
	char		*line;

		line = NULL;
		while (1)
		{
			if (read(fd, buf[fd], BUFFER_SIZE) == -1)
            {
                if (line)
                    free(line);
                return (NULL);
            }
            line = ft_strjoin(line, buf[fd]);
			if (!line)
				return (NULL);
            if (next_line_in_buf(line))
                break ;
        }
		return (cut_next_line(line));
}
