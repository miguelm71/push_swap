/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:21:46 by mmateo-m          #+#    #+#             */
/*   Updated: 2023/04/03 07:09:43 by mmateo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"



typedef struct s_flags
{
	int		minus;
	int		plus;
	int		pad;
	int		space;
	int		dot;
	int		zero;
	int		width;
	int		decimals;
	char	data_type;
	long	number;
}t_flags;

typedef struct s_tp
{
	int		zero_l;
	int		decimal_z;
	int		space_l;
	int		space_r;
	int		sign;
	int		sign_space;
	int		cap_hex;
	int		low_hex;
}t_tp;


//  ft_flags1
int		ft_get_flags(char **str, va_list *param_ptr);

//  ft_flags2
int		ft_is_flag(char c);
int		ft_is_type(char c);
t_flags	*ft_init_flags(void);
void	ft_end_flags(t_flags *flags);
int		ft_set_type_flag(char t, t_flags *flags);

//  ft_flags3
int		ft_parse_flags(char **str, t_flags *flags);
int		ft_get_num(char **str);
int		ft_set_flag_number(int n, t_flags *flags);
int		ft_set_minus_flag(t_flags *flags);

//  ft_flags4 
int		ft_set_zero_flag(t_flags *flags);
int		ft_set_dot_flag(t_flags *flags);
int		ft_set_plus_flag(t_flags *flags);
int		ft_set_space_flag(t_flags *flags);
int		ft_set_pad_flag(t_flags *flags);

//  ft_printer1
t_tp	*ft_init_to_print(void);
int		ft_print_param(t_flags *flags, va_list *param_ptr);
int		ft_print_char(t_flags *flags, va_list *param_ptr);
int		ft_print_string(t_flags *flags, va_list *param_ptr);
int		ft_print_pointer(t_flags *flags, va_list *param_ptr);

//ft_printer2
int		ft_print_decimal(t_flags *flags, va_list *param_ptr);
int		ft_print_unsigned(t_flags *flags, va_list *param_ptr);
int		ft_print_hex(t_flags *flags, va_list *param_ptr, int low);
int		ft_print_percentage(t_flags *flags);

//ft_printer3
void	ft_process_f_s_pad(t_tp *tp, t_flags *flags, char **str, int n);
void	ft_process_flags(t_tp *tp, t_flags *flags, char **str);
int		ft_write_xchars(char c, int n);
int		ft_write_char(t_tp *tp, char c);
int		ft_write_string(t_tp *tp, char *str, char t);

//ft_printer4
void	ft_calculate_width_zdot(t_tp *tp, t_flags *flags, int n);
void	ft_calculate_width(t_tp *tp, t_flags *flags, char *str);

//ft_printf_utils
int		ft_plen(unsigned long int n, unsigned int b_len);
int		ft_dlen(long long int n, unsigned int b_len);
char	*ft_p2string(unsigned long p);
char	*ft_d2string(long p, char *base);
#endif