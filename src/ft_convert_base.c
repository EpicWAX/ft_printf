/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/30 14:02:52 by qhusler           #+#    #+#             */
/*   Updated: 2016/06/19 19:39:51 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*g_result;

char	*ft_calc_in_base(int nb, int len_base, char *base_to, int signe)
{
	int i;

	if (nb == 0)
		return ("0\0");
	i = 0;
	while (nb > 0)
	{
		g_result[i++] = base_to[nb % len_base];
		nb = nb / len_base;
	}
	if (signe == -1)
		g_result[i++] = '-';
	g_result[i] = '\0';
	ft_strrev(g_result);
	return (g_result);
}

void	ft_init_result(int nb, int len_base)
{
	int tmp;
	int i;

	i = 0;
	tmp = nb;
	while (tmp /= len_base)
		i++;
	g_result = (char*)malloc(sizeof(g_result) * (i + 1));
}

int		ft_atoi_base(char *str, char *base, int len_base)
{
	int number;
	int j;

	if (*str == '-' || *str == '+')
		str++;
	number = 0;
	while (*str != '\0')
	{
		number *= len_base;
		j = 0;
		while (*str != base[j])
			j++;
		number += j;
		str++;
	}
	ft_init_result(number, len_base);
	return (number);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int i;
	int len_base_from;
	int len_base_to;
	int len_nbr;
	int signe;

	i = 0;
	len_nbr = ft_strlen(nbr);
	len_base_to = ft_strlen(base_to);
	len_base_from = ft_strlen(base_from);
	signe = (nbr[i] == '-') ? -1 : 1;//
	len_nbr += (nbr[i] == '-') ? -1 : 0;//
	return (ft_calc_in_base(ft_atoi_base(nbr, base_from, len_base_from), len_base_to, base_to, signe));
}
