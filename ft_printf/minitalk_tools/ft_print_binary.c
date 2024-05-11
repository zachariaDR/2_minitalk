/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:12:21 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 11:06:09 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	ft_print_binary(char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 128)
			ft_printf(" %d ", 1);
		else
			ft_printf(" %d ", 0);
		ft_printf(" ");
		c <<= 1;
		i++;
	}
	ft_printf("\n");
}
