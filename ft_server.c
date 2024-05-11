/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:32:02 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 13:53:00 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/minitalk_tools/minitalk_tools.h"

void	build_str(t_var *v, int *client_pid)
{
	// if (v->recieved == 8)
	// 	mini_banner(0, 0, 2);
	if (bytes_nb(v->c) == 0 || bytes_nb(v->c) > 1)
	{
		if (bytes_nb(v->c) != 0)
		{
			v->buffer_need = bytes_nb(v->c);
			ft_allocate(&(v->s), bytes_nb(v->c) + 1, NULL);
			v->i = 0;
		}
		if (v->i < v->buffer_need)
		{
			v->s[v->i] = v->c;
			v->i = v->i + 1;
		}
		if (v->i == v->buffer_need)
		{
			v->s[v->i] = '\0';
			ft_printf("%s", v->s);
			free(v->s);
		}
	}
	if (bytes_nb(v->c) == 1)
		ft_printf("%c", v->c);
	(v->str)[v->index] = v->c;
	if (v->c == '\0')
	{
		mini_banner(*client_pid, v->recieved, 3);
		if (kill(*client_pid, SIGUSR1) == -1)
			signal_error(1);
		if (ft_strncmp(v->str, STOP_MSG, ft_strlen(STOP_MSG)) == 0)
		{
			mini_banner(0, 0, 4);
			free(v->str);
			exit(EXIT_SUCCESS);
		}
		v->recieved = 0;
		free(v->str);
		return ;
	}
	v->bit = 0;
	v->index = v->index + 1;
}

void	build_size(t_var *v, int *order, int *client_pid)
{
	if (v->c != '\0')
	{
		v->size_str *= 10;
		v->size_str += ft_atoi_c(v->c);
	}
	if (v->c == '\0')
	{
		if (kill(*client_pid, SIGUSR1) == -1)
			signal_error(1);
		v->recieved = 0;
		v->c = 0;
		*order = 1;
	}
	v->bit = 0;
}

void	action(int sig, siginfo_t *info, void *context)
{
	static int		client_pid;
	static int		current_pid;
	static int		help;
	static t_var	v;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	current_pid = info->si_pid;
	if (help == 1)
		ft_allocate(&(v.str), v.size_str, &help);
	if (client_pid != current_pid)
		re_initialase(&v, &client_pid, &current_pid, &help);
	(build_character(&(v.c), sig), ft_increment(&(v.recieved), &(v.bit)));
	if (v.bit == 8)
	{
		if (help == 0)
			build_size(&v, &help, &client_pid);
		else if (help == 2)
			build_str(&v, &client_pid);
	}
	v.c <<= 1;
	usleep(120);
	if (kill(client_pid, SIGUSR2) == -1)
		signal_error(1);
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	if (pid < 1)
		signal_error(1);
	mini_banner(pid, 0, 1);
	act.sa_sigaction = action;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (EXIT_FAILURE);
}
