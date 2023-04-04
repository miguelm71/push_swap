/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 07:27:10 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/04 09:03:50 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_e(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd) != NULL)
		i++;
	return (i);
}

void ft_init_stacks()

int	main()//int arg, char **argv)
{
	char	*f = "example";
	int		fd;

	fd = open(f, O_RDONLY);
	ft_printf("%d", ft_count_e(fd));
}