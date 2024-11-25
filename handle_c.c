/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:01:23 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/20 18:01:24 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(char c, t_flags flags)

{
	int	x;

	x = 0;
	if (flags.minus)
	{
		x += (int)write(1, &c, 1);
		while (x < flags.width)
			x += (int)write(1, " ", 1);
	}
	else
	{
		while (x < flags.width - 1)
			x += (int)write(1, " ", 1);
		x += (int)write(1, &c, 1);
	}
	return (x);
}