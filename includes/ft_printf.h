/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcloves <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 20:43:24 by hcloves           #+#    #+#             */
/*   Updated: 2020/08/01 20:44:54 by hcloves          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define DEF   "\x1B[0m"

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct	s_printf
{
	char			is_sign;
	int				width;
	int				precision;
	int				precision_width;
	int				precision_parsing;
	int				conversion_type;
	int				minus;
	int				zero;
	int				plus;
	int				space;
	int				sharp;
	int				len;
	int				gaps_len;
	int				is_int;
	int				h_count;
	int				l_count;
	int				lf_count;
	intmax_t		n;
	uintmax_t		u;
	long double		f;
	int				is_nan;
	int				is_inf;
	int				is_neg;
	int				flag_p;
	int				i;
	int				ret;
}				t_data_struct;

void			fixer_condition(char *str, int number, \
				t_data_struct *data, int neg);
int				ft_printf(const char *str, ...);
void			check_prec_wid(char *str, va_list next_argument, \
				t_data_struct *data);
void			print_other(t_data_struct *data, char *str, int len);
void			to_s(va_list next_argument, t_data_struct *data);
void			to_i_d(va_list next_argument, t_data_struct *data);
void			to_u(va_list next_argument, t_data_struct *data);
void			to_x(va_list next_argument, t_data_struct *data);
void			to_c(va_list next_argument, t_data_struct *data);
void			to_o_u_b(va_list next_argument, t_data_struct *data);
void			to_f(va_list next_argument, t_data_struct *data);
void			size_uint(va_list next_argument, t_data_struct *data);
char			*strdup_l(char *s, t_data_struct *data);
char			*print_gaps(t_data_struct *data);
char			*zero_precision(char *str, t_data_struct *data);
void			output_print(char *str, char *gaps, t_data_struct *data);
void			write_sign(t_data_struct *data);
int				atoi_start_i(char *str, int *i);
char			*itoa_intmax(intmax_t n);
int				correct_character2(char c);
int				correct_character(char c);
void			select_conv_type(va_list next_arg, \
				t_data_struct *data, char *str);
void			parse3(t_data_struct *data, char *c, char *str);
void			remember_flag_mod(t_data_struct *data, char *str);
int				parse2(char *str, va_list next_arg, t_data_struct *data);
void			parse(char *str, va_list next_arg, t_data_struct *data);
char			*o_u_b_itoa(uintmax_t n, int system);
size_t			o_u_b_x_len(uintmax_t n, int system);
void			prefix(t_data_struct *data);
size_t			intmax_len(intmax_t n);
void			strlen_and_zero(char *str, t_data_struct *data);
int				free_str(t_data_struct *data, char **str);
void			size_float(va_list next_argument, t_data_struct *data);
int				float_nan(t_data_struct *data);
int				float_inf(t_data_struct *data);
void			edit_flag(t_data_struct *data);
void			rounding(t_data_struct *data);
long double		number_characteristic(int pow);
char			*left_float(long double f);
char			*right_float(long double f, int p, char *left_float);
int				count_left_float(long double f);
long double		atoi_float(char *s);
int				is_not_even_str(char *str);
void			output_print_f(t_data_struct *data, \
				char *left_str, char *right_str);
void			signe_f(t_data_struct *data);
void			pad_block_f(t_data_struct *data, int flag);
void			write_padding(int len, char c);
void			block_len_f(char *left_str, t_data_struct *data);
void			edit_flag2(t_data_struct *data);
void			strlen_and_zero_noliked(char **str, t_data_struct *data);
char			*itoa_x_xx(uintmax_t n, char *str_16form);
void			size_int(va_list next_argument, t_data_struct *data);
void			free_float(char **left_str, char **right_str);
int				free_str_i(t_data_struct *data, char **str);
void			long_double_fixer(t_data_struct *data);
void			long_double_fixer_plus(t_data_struct *data, int number);
void			long_double_fixer_neg(t_data_struct *data, int number);
void			to_p(va_list next_argument, t_data_struct *data);

#endif
