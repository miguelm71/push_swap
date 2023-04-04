/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:55:08 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:36:17 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

int	ft_have_n(char *b)
{
	int	n;

	n = -1;
	if (b == NULL)
		return (-1);
	while (b[++n] != '\n')
	{
		if (b[n] == '\0' )
			return (-1);
	}
	return (n);
}

char	*ft_calloc_c(char c, int size)
{
	char	*str;
	int		n;

	str = malloc (sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	n = 0;
	while (n < size)
	{
		str[n] = c;
		n++;
	}
	return (str);
}

void	ft_strsplit_n(char **h, char **p)
{
	char	*n;
	int		n_pos;

	n_pos = ft_have_n(*h);
	if (n_pos != -1)
	{
		*p = ft_copy_str(*h, 0, n_pos + 1);
		n = ft_copy_str(*h, n_pos + 1, -1);
		free (*h);
		*h = n;
	}
	else
	{
		n = ft_copy_str (*h, 0, -1);
		free (*h);
		*h = NULL;
		*p = n;
	}
}

char	*ft_copy_str(char *str, int i, int e)
{
	int		j;
	char	*new;
	int		l;

	j = 0;
	l = ft_strlen(str);
	if (str == NULL || l == 0 || l == i)
		return (NULL);
	if (e < i || e > (int)ft_strlen (str))
		e = ft_strlen(str);
	new = malloc (sizeof(char) * (e - i) + 1);
	while (j + i < e)
	{
		new[j] = str[j + i];
		j++;
	}
	new [j] = '\0';
	return (new);
}
