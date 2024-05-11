/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:30:07 by zadriouc          #+#    #+#             */
/*   Updated: 2024/05/06 17:06:06 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* Libc functions */
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *c);
int					ft_atoi_c(char c);
char				*ft_itoa(int n);
char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
