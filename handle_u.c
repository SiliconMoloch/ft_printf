/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:36:28 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/20 16:36:29 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_u_base(unsigned int n, char *base)

{
	int	x;

	x = 0;
	if (n >= 10)
		x += ft_putnbr_u_base(n / 10, base);
	x += (int)write(1, &base[n % 10], 1);
	return (x);
}

static int	digits_count_u(unsigned int n)

{
	int	digits;

	digits = 1;
	while (n >= 10)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

int	handle_u(unsigned int n, t_flags flags)

{
	int	x;
	int	digits;
	int	total_length;

	x = 0;
	digits = digits_count_u(n);
	if (n == 0 && flags.precision == 0)
		digits = 0;
	total_length = digits;
	if (flags.precision > digits)
		total_length += flags.precision - digits;
	if (!flags.minus)
		x += padding_print(flags.width - total_length, flags);
	x += precision_print(flags.precision, digits);
	if (digits > 0)
		x += ft_putnbr_u_base(n, RADIX_10);
	if (flags.minus)
		x += padding_print(flags.width - total_length, flags);
	return (x);
}
