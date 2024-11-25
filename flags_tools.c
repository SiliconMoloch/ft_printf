/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:59:26 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/21 15:59:27 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding_print(int padding, t_flags flags)

{
	int	x;

	x = 0;
	while (padding > 0)
	{
		if (!flags.minus && flags.zero && flags.precision == -1)
			x += (int)write(1, "0", 1);
		else
			x += (int)write(1, " ", 1);
		padding--;
	}
	return (x);
}

int	precision_print(int precision, int digits)

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
