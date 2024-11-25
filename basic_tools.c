/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:56:32 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/22 16:03:29 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)

{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_base(int n, char *base)

{
	int	x;

	x = 0;
	if (n == INT_MIN && (int)ft_strlen(base) == 10)
	{
		x += (int)write(1, "2147483648", 10);
		return (x);
	}
	if (n >= (int)ft_strlen(base))
		x += ft_putnbr_base(n / (int)ft_strlen(base), base);
	x += (int)write(1, &base[n % (int)ft_strlen(base)], 1);
	return (x);
}

int	digits_count(int n, int base_length)

{
	int	digits;

	digits = 1;
	while (n >= base_length)
	{
		n /= base_length;
		digits++;
	}
	return (digits);
}

int	ft_abs(int n)

{
	if (n < 0)
		return (-n);
	return (n);
}

int	specifier(char c)

{
	if (c == 'd' || c == 'i' || c == 'u'
		|| c == 's' || c == 'c'
		|| c == 'x' || c == 'X'
		|| c == 'p'
		|| c == '%')
		return (1);
	return (0);
}
