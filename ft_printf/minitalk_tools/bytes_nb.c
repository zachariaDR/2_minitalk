/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:44:38 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 13:58:25 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

int	bytes_nb(char c)
{
	int	i;
	int	ones;

	ones = 0;
	i = 0;
	while ((i < 8) && (c & 128))
	{
		ones++;
		c <<= 1;
	}
	if (ones == 1)
		return (0);
	if (ones == 0)
		return (1);
	return (ones);
}
