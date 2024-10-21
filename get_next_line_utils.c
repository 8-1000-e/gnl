/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edubois- <edubois-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:37:15 by edubois-          #+#    #+#             */
/*   Updated: 2024/10/21 02:34:59 by edubois-         ###   ########.fr       */
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