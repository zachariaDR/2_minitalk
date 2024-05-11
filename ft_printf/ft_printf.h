/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:35:34 by zadriouc          #+#    #+#             */
/*   Updated: 2023/12/12 14:00:54 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define U "0123456789"
# define HEX "0123456789abcdef"
# define UPHEX "0123456789ABCDEF"

int	ft_putnbr_base(unsigned int nbr, char uxX);
int	ft_putp(void *p);
int	ft_printf(const char *format, ...);

#endif
