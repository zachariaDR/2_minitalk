/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 02:30:04 by zadriouc          #+#    #+#             */
/*   Updated: 2023/12/13 18:05:40 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_type(va_list args, const char format)
{
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (format == '%')
		return (ft_putchar_fd(format, 1));
	else if (format == 'u' || format == 'x' || format == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int), format));
	else if (format == 'p')
		return (ft_putp(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			count += check_type(args, format[i + 1]);
			i++;
		}
		else if (format[i] != '%')
			count += ft_putchar_fd(format[i], 1);
		if (format[i])
			i++;
	}
	va_end(args);
	return (count);
}
