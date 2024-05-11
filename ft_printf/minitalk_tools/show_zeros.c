/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_zeros.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:51:24 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/08 14:51:26 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

char	*show_zeros(int total_l, int nb)
{
	int		i;
	int		gap;
	char	*s;

	gap = total_l - ft_strlen(ft_itoa(nb));
	s = (char *)malloc(sizeof(char) * (gap + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (i++ < gap - 1)
		s[i] = '0';
	s[i] = '\0';
	return (s);
}
