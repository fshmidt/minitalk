/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:55:36 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 23:39:45 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	a;

	a = 0;
	if ((dest == 0 && src == 0) || (unsigned char)src == (unsigned char)dest)
		return (0);
	if (dest == src || n == 0)
		return (dest);
	d = (char *)dest;
	s = (char *)src;
	while (n - a)
	{
		d[a] = s[a];
		a++;
	}
	return (d);
}
