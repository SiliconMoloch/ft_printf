/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:50:16 by yabokhar          #+#    #+#             */
/*   Updated: 2024/11/22 13:40:18 by yabokhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	specifer_handler(va_list arguments, t_flags flags)

{
	if (flags.specifier == 'c')
		return (handle_c(va_arg(arguments, int), flags));
	if (flags.specifier == 's')
		return (handle_s(va_arg(arguments, const char *), flags));
	if (flags.specifier == 'd' || flags.specifier == 'i')
		return (handle_d_and_i(va_arg(arguments, int), flags));
	if (flags.specifier == 'u')
		return (handle_u(va_arg(arguments, unsigned int), flags));
	if (flags.specifier == 'x')
		return (handle_x_l(va_arg(arguments, unsigned int), flags));
	if (flags.specifier == 'X')
		return (handle_x_u(va_arg(arguments, unsigned int), flags));
	if (flags.specifier == 'p')
		return (handle_p(va_arg(arguments, void *), flags));
	if (flags.specifier == '%')
		return ((int)write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)

{
	int		x;
	va_list	arguments;
	t_flags	flags;

	if (!format)
		return (-1);
	va_start(arguments, format);
	x = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			initialize_flags(&flags);
			format = parse_flags(format, &flags);
			if (flags.specifier)
				x += specifer_handler(arguments, flags);
		}
		else
			x += (int)write(1, &(*format), 1);
		format++;
	}
	va_end(arguments);
	return (x);
}
