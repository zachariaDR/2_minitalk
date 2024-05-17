/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:34:09 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/12 11:16:01 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	ft_allocate(char **str, int size, int *help)
{
	*str = (char *)malloc((size + 1) * sizeof(char));
	if (!(str))
		signal_error(1);
	if (help)
		*help = 2;
}
