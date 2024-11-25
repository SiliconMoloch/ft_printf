/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:45:47 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/22 16:04:50 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define RADIX_10 "0123456789"
# define RADIX_16_UPPERCASE "0123456789ABCDEF"
# define RADIX_16_LOWERCASE "0123456789abcdef"

# include "stdarg.h"
# include "unistd.h"
# include "stdlib.h"
# include "limits.h"
# include "stdint.h"

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		hash;
	int		space;
	int		plus;
	int		width;
	int		precision;
	char	specifier;
}		t_flags;

void		initialize_flags(t_flags *flags);
const char	*parse_flags(const char *format, t_flags *flags);
size_t		ft_strlen(const char *s);
int			ft_putnbr_base(int n, char *base);
int			digits_count(int n, int base_length);
int			specifier(char c);
int			ft_abs(int n);
int			padding_print(int padding, t_flags flags);
int			precision_print(int precision, int digits);
int			handle_x_l(unsigned int n, t_flags flags);
int			handle_x_u(unsigned int n, t_flags flags);
int			handle_d_and_i(int n, t_flags flags);
int			handle_c(char c, t_flags flags);
int			handle_s(const char *s, t_flags flags);
int			handle_u(unsigned int n, t_flags flags);
int			handle_p(void *ptr, t_flags flags);

#endif
