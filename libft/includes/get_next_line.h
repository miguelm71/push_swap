/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 09:54:52 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:35:34 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"

//get_next_line
char	*ft_increase_buf(char **s);

//get_next_line_utils
int		ft_have_n(char *b);
char	*ft_calloc_c(char c, int size);
void	ft_strsplit_n(char **h, char **p);
char	*ft_copy_str(char *str, int i, int e);

#endif