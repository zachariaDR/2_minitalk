/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:34:17 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/07 18:51:40 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	signal_error(int op)
{
	if (op == 0)
		ft_printf("\nclient: unexpected error.\n");
	else if (op == 1)
		ft_printf("\nserver: unexpected error.\n");
	exit(EXIT_FAILURE);
}
