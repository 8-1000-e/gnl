/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42angouleme>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:33:59 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/16 03:37:52 by edubois-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int c;

    c = 0;
    while (*s++)
        c++;
    return (c);
}
char    *ft_strcat(char *s, char *s2)
{
    char  *save_s;

    save_s = s;
    if (s2)
    {
        s + ft_strlen(s);
        while (*s2)
         *s++ = *s2++;
        *s = '\0';
    }
    return (save_s);

}

char *ft_realloccat(char *line, char *buf, int nb_realloc)
{
    int     buf_size;
    char    *buf_tmp;
    char    *save_buf;

    buf_size = BUFFER_SIZE;
    buf_tmp = malloc(BUFFER_SIZE * (nb_realloc) + 1);
    if (!buf_tmp && line)
    {
        free(line);
        return (NULL);
    }
    save_buf = buf_tmp;
    ft_strcat(buf_tmp, buf);
    ft_strcat(buf_tmp, line);
    buf_tmp + (ft_strlen(line) + ft_strlen(buf));
    free(line);
    while(buf_size--)
        *buf_tmp++ = '\0';
    return (save_buf);
}

int next_line_in_buf(char *buf)
{
    if (!buf)
        return (0);
    while(*buf && *buf != '\n')
        buf++;
    if (!buf)
        return (0);
    return (1);
}
char *cut_next_line(char *buf)
{
    char *save_buf;

    save_buf = buf;
    while (*buf && *buf != '\0')
        buf++;
    if (*buf)
    {
        while(*buf)
            *buf++ = '\0';
    }
    return (save_buf);
}

char    *get_next_line(int fd)
{
    char *buf;
    int nb_realloc_buf_size;
    char *line;

    line = NULL;
    nb_realloc_buf_size = 0;
    buf = malloc(BUFFER_SIZE);
    if (!buf)
        return(NULL);
    while(!next_line_in_buf(line));
    {
        read(fd, buf, BUFFER_SIZE);
        nb_realloc_buf_size ++;
        line = ft_realloccat(line , buf, nb_realloc_buf_size);
        if (!line)
            return (NULL);
    }
    if (next_line_in_buf(line))
        return (cut_next_line(line));
    return (NULL);
    }

int main()
{
    get_next_line(0);
}



