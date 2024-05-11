/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:45:18 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/08 14:52:00 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/minitalk_tools/minitalk_tools.h"

void	char_to_bin(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 128)
		{
			if (kill(pid, SIGUSR2) == -1)
				signal_error(0);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				signal_error(0);
		}
		c <<= 1;
		bit++;
		pause();
		usleep(120);
	}
}

void	sent_text(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		char_to_bin(str[i++], pid);
	char_to_bin('\0', pid);
}

void	recieved(int sig)
{
	static int	sent;
	static int	order;

	if (sig == SIGUSR1 && order == 0)
		order = 1;
	else if (sig == SIGUSR1 && order == 1)
	{
		ft_printf("\n-- %d signal sent successfully! ✅ --\n", sent);
		exit(EXIT_SUCCESS);
	}
	if (sig == SIGUSR2 && order == 1)
		++sent;
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	client_pid;

	client_pid = getpid();
	if (ac == 3)
	{
		mini_banner(client_pid, 0, 0);
		signal(SIGUSR1, recieved);
		signal(SIGUSR2, recieved);
		server_pid = ft_atoi(av[1]);
		ft_printf("\n-- Text currently sending.. ⌛ --\n\n");
		sent_text(ft_itoa(ft_strlen(av[2])), server_pid);
		sent_text(av[2], server_pid);
	}
	else
		ft_printf("usage: ./client <server_pid> <text to send>\n");
	return (EXIT_FAILURE);
}
