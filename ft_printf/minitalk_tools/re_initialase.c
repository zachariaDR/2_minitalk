/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_initialase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:35:45 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/05 18:05:07 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	re_initialase(t_var *v, int *client_pid, int *current_pid, int *order)
{
	v->bit = 0;
	v->c = 0;
	v->recieved = 0;
	v->index = 0;
	v->size_str = 0;
	*client_pid = *current_pid;
	*order = 0;
}
