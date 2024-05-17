/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundle_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 10:24:37 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/12 11:01:53 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	ft_hundle_unicode(char c, char **s, int *i, int *buff)
{
	if (bytes_nb(c) != 0)
	{
		*buff = bytes_nb(c);
		ft_allocate(s, bytes_nb(c) + 1, NULL);
		*i = 0;
	}
	if (*i < *buff)
	{
		(*s)[*i] = c;
		*i = *i + 1;
	}
	if (*i == *buff)
	{
		(*s)[*i] = '\0';
		ft_printf("%s", *s);
		free(*s);
	}
}
