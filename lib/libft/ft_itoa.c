/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadriouc <zadriouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:07:47 by zadriouc          #+#    #+#             */
/*   Updated: 2023/12/01 18:04:20 by zadriouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		end;

	i = 0;
	end = ft_strlen(str) - 1;
	while (i <= end / 2)
	{
		tmp = str[end - i];
		str[end - i] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}

static int	ft_len_of(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_if_negative(int n, unsigned int *nbr, size_t *nlen)
{
	if (n <= 0)
	{
		*nbr = -n;
		*nlen += 1;
	}
}

static void	ft_implement(char *str, unsigned int nbr, int n)
{
	int	i;

	i = 0;
	if (nbr == 0)
		str[i++] = '0';
	while (nbr)
	{
		str[i] = (nbr % 10) + '0';
		nbr /= 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = 0;
}

char	*ft_itoa(int n)
{
	char			*strnum;
	size_t			len;
	unsigned int	nbr;

	nbr = n;
	len = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	ft_if_negative(n, &nbr, &len);
	len = len + ft_len_of(n);
	strnum = malloc(sizeof(char) * (len + 1));
	if (!strnum)
		return (NULL);
	ft_implement(strnum, nbr, n);
	return (ft_strrev(strnum));
}
