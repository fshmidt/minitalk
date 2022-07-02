/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:55:31 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 15:27:55 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			a;
	int				diff;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	a = 0;
	diff = 0;
	while (n > a)
	{
		if (c1[a] == c2[a])
			a++;
		else
			return ((int)(c1[a] - c2[a]));
	}
	return (0);
}
