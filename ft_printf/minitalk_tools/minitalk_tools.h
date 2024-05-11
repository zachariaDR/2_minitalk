/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_tools.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:47:58 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/11 13:57:41 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_TOOLS_H
# define MINITALK_TOOLS_H

# include "../ft_printf.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

# define STOP_MSG "KILL SERVER"

typedef struct s_var
{
	char	*str;
	char	*s;
	char	c;
	int		recieved;
	int		bit;
	int		index;
	int		size_str;
	int		i;
	int		buffer_need;
}			t_var;

/* Extra Functions */
void		re_initialase(t_var *v, int *client_pid, int *current_pid,
				int *order);
void		signal_error(int op);
char		*show_zeros(int total_l, int nb);
void		build_character(char *c, int sig);
void		ft_increment(int *a, int *b);
void		ft_allocate(char **str, int size, int *help);
void		mini_banner(int s_pid, int nb, int op);
int			bytes_nb(char c);
#endif
