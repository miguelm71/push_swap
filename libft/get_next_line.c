/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:55:03 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:34:01 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <stdio.h>

char	*ft_increase_buf(char **s)
{
	int		len;
	char	*n;
	int		i;
	char	x;

	len = ft_strlen(*s);
	n = ft_calloc_c('\0', (sizeof(char) * (BUFFER_SIZE + len + 1)));
	if (n == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		x = (*s)[i];
		n[i] = x;
		i++;
	}
	free (*s);
	return (n);
}

char	*ft_free(char **p)
{
	free (*p);
	*p = NULL;
	return (*p);
}

char	*get_next_line(int fd)
{
	char static	*head;
	char		*pos;
	int			n_pos;
	int			c_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ft_free(&head));
	n_pos = ft_have_n(head);
	if (n_pos == -1)
	{
		while (n_pos < 0)
		{
			head = ft_increase_buf(&head);
			if (head == NULL)
				return (NULL);
			pos = &head[ft_strlen(head)];
			c_read = read(fd, pos, BUFFER_SIZE);
			n_pos = ft_have_n(head);
			if (c_read < BUFFER_SIZE || (-1 < n_pos))
				break ;
		}
	}
	ft_strsplit_n(&head, &pos);
	return (pos);
}
