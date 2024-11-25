/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 01:19:11 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/21 01:19:12 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	padding_print_x_l(int padding_length, t_flags flags, int hash_flag)

{
	int	x;

	x = 0;
	if (hash_flag)
		padding_length -= 2;
	while (padding_length > 0)
	{
		if (!flags.minus && flags.zero && flags.precision == -1)
			x += (int)write(1, "0", 1);
		else
			x += (int)write(1, " ", 1);
		padding_length--;
	}
	return (x);
}

static int	ft_putnbr_x_l(unsigned int n)

{
	int	x;

	x = 0;
	if (n >= 16)
		x += ft_putnbr_x_l(n / 16);
	x += (int)write(1, &RADIX_16_LOWERCASE[n % 16], 1);
	return (x);
}

static int	digits_count_x_l(unsigned int n)

{
	int	digits;

	digits = 1;
	while (n >= 16)
	{
		n /= 16;
		digits++;
	}
	return (digits);
}

static int	precision_print_x_l(int precision, int digits)

{
	int	x;

	x = 0;
	while (precision > digits)
	{
		x += (int)write(1, "0", 1);
		precision--;
	}
	return (x);
}

int	handle_x_l(unsigned int n, t_flags flags)

{
	int	x;
	int	hash_flag;
	int	digits;
	int	total_length;
	int	padding;

	x = 0;
	hash_flag = (flags.hash && n != 0);
	digits = digits_count_x_l(n);
	total_length = digits;
	if (flags.precision > digits)
		total_length = flags.precision;
	if (n == 0 && flags.precision == 0)
		total_length = 0;
	padding = flags.width - total_length;
	if (!flags.minus)
		x += padding_print_x_l(padding, flags, hash_flag);
	if (hash_flag)
		x += (int)write(1, "0x", 2);
	x += precision_print_x_l(flags.precision, digits);
	if (total_length > 0)
		x += ft_putnbr_x_l(n);
	if (flags.minus)
		x += padding_print_x_l(padding, flags, hash_flag);
	return (x);
}
