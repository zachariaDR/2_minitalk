/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:39 by zadriouc          #+#    #+#             */
/*   Updated: 2023/12/13 03:14:42 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char uxX)
{
	unsigned int	base_len;
	char			*base;
	int				count;

	if (uxX == 'u')
		base = U;
	if (uxX == 'x')
		base = HEX;
	if (uxX == 'X')
		base = UPHEX;
	count = 0;
	base_len = ft_strlen(base);
	if (nbr >= base_len)
	{
		count += ft_putnbr_base(nbr / base_len, uxX);
		count += ft_putnbr_base(nbr % base_len, uxX);
	}
	else
		count += ft_putchar_fd(base[nbr], 1);
	return (count);
}
