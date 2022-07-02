/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:28:03 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 23:24:36 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

static int	ft_sizeofn(int n)
{
	int	i;

	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{
		i = 1;
		n = -1 * n;
	}
	else
		i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (!i)
		return (1);
	return (i);
}

char	*ft_itoa(int n)
{
	int		number;
	char	*str;

	number = ft_sizeofn(n);
	str = malloc((number + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	else if (!n)
		str[0] = '0';
	str[number] = '\0';
	while (n)
	{
		str[--number] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
