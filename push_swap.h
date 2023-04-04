/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 08:59:08 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/04 09:41:19 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "libft/includes/libft.h"

typedef struct s_stack_e
{
	int					e;
	struct s_stack_e	*n;
	struct s_stack_e	*p;
}t_stack_e;


#endif