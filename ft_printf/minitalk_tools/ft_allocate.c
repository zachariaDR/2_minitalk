/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:34:09 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 13:48:47 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	ft_allocate(char **str, int size, int *help)
{
	*str = (char *)malloc(size + 1);
	if (!(str))
		signal_error(1);
	if (help)
		*help = 2;
}
