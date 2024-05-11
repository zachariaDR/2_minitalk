/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_banner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:46:39 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 13:57:00 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_tools.h"

void	recieved_msg(void)
{
	ft_printf(" -----------------------------------------------------\n");
	ft_printf("|                ⬇️  Message Received ⬇️                |\n");
	ft_printf(" -----------------------------------------------------\n\n");
}

void	finish_msg(void)
{
	ft_printf("\n\n -------------------------------------------------------\n");
	ft_printf(" -----| SERVER JOB END HERE 📌 HAVE A NICE DAY 🥴 |-----\n");
	ft_printf(" -------------------------------------------------------\n");
}

void	mini_banner(int cs_pid, int nb, int op)
{
	if (op == 0 || op == 1)
	{
		ft_printf("\n --------------------| MINI-TALK |--------------------\n");
		if (op == 1)
			ft_printf("|               SERVER PID :  %s%d                    |\n", show_zeros(5, cs_pid), cs_pid);
		else
			ft_printf("|               CLIENT PID :  %s%d                    |\n", show_zeros(5, cs_pid), cs_pid);
		ft_printf("|      TO STOP SERVER SEND : \"KILL SERVER\"             |\n");
		ft_printf(" ------------------------------------------------------\n\n");
	}
	if (op == 2)
		recieved_msg();
	if (op == 3)
	{
		ft_printf("\n\n -----------------------------------------------------\n");
		ft_printf("|    %s%d signal recieved from client PID: %d    |\n", show_zeros(6, nb), nb, cs_pid);
		ft_printf(" -----------------------------------------------------\n");
	}
	if (op == 4)
		finish_msg();
}
