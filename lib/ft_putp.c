/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:34:03 by zadriouc          #+#    #+#             */
/*   Updated: 2023/12/12 21:18:25 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnp(unsigned long int nbr)
{
	unsigned long int	base_len;
	int					count;

	count = 0;
	base_len = ft_strlen(HEX);
	if (nbr >= base_len)
	{
		count += ft_putnp(nbr / base_len);
		count += ft_putnp(nbr % base_len);
	}
	else
		count += ft_putchar_fd(HEX[nbr % base_len], 1);
	return (count);
}

int	ft_putp(void *p)
{
	unsigned long	n;
	int				count;

	count = 0;
	n = (unsigned long)p;
	count += ft_putstr_fd("0x", 1);
	if (!p)
		count += ft_putstr_fd("0", 1);
	else
		count += ft_putnp(n);
	return (count);
}
