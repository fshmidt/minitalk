/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:53:24 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 00:41:44 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checktni(unsigned long long int tni, int minusi)
{
	int	a;

	a = tni / 4294967296;
	if (tni > 9223372036854775807 && minusi < 0)
		return (0);
	if (tni > 9223372036854775807)
		return (-1);
	if (tni < 2147483648 || (tni == 2147483648 && minusi < 0))
		return ((int)tni * minusi);
	else if (tni > 2147483647 && minusi > 0)
	{
		if (a)
			tni = tni % 4294967296;
		if (tni > 2147483647)
			return ((int)(tni - 4294967296));
		return ((int)tni);
	}
	else
	{
		if (a)
			tni = tni % 4294967296;
		if (tni > 2147483648)
			return ((int)((-1) * (tni - 4294967296)));
		return ((int)tni * (-1));
	}
}

int	ft_atoi(const char *str)
{
	int						i;
	int						minusi;
	unsigned long long int	tni;

	i = 0;
	minusi = 1;
	tni = 0;
	while (((str[i] <= 13) && (str[i] >= 9)) || ((str[i] == ' ')))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			minusi = minusi * (-1);
		i++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		tni = (tni * 10) + str[i] - 48;
		i++;
	}
	return (checktni(tni, minusi));
}
