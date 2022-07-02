/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:55:48 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:05:39 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			a;
	unsigned char	*d;

	d = (unsigned char *)str;
	a = 0;
	while (len - a)
	{
		d[a] = c;
		a++;
	}
	return (d);
}
