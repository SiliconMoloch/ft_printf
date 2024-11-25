/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:51:15 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/21 14:51:16 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_count_p(uintptr_t n)

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

static int	ft_putnbr_p(uintptr_t n)

{
	int	x;

	x = 0;
	if (n >= 16)
		x += ft_putnbr_p(n / 16);
	x += (int)write(1, &RADIX_16_LOWERCASE[n % 16], 1);
	return (x);
}

static int	null_pointer_handling(t_flags flags)

{
	int	x;
	int	total_length;
	int	padding;

	x = 0;
	total_length = 5;
	padding = flags.width - total_length;
	if (!flags.minus)
		x += padding_print(padding, flags);
	x += (int)write(1, "(nil)", 5);
	if (flags.minus)
		x += padding_print(padding, flags);
	return (x);
}

int	handle_p(void *ptr, t_flags flags)

{
	int	x;
	int	total_length;
	int	padding;

	x = 0;
	total_length = digits_count_p((uintptr_t)ptr) + 2;
	if (!ptr)
		return (null_pointer_handling(flags));
	if (flags.precision > digits_count_p((uintptr_t)ptr))
		total_length = flags.precision;
	if (flags.precision == 0)
		total_length = 0;
	padding = flags.width - total_length;
	if (padding < 0)
		padding = 0;
	if (!flags.minus)
		x += padding_print(padding, flags);
	x += precision_print(flags.precision, digits_count_p((uintptr_t)ptr));
	x += (int)write(1, "0x", 2);
	if (total_length > 0)
		x += ft_putnbr_p((uintptr_t)ptr);
	if (flags.minus)
		x += padding_print(padding, flags);
	return (x);
}
