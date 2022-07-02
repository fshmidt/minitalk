/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:55:44 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 23:41:15 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	a;

	d = (char *)dst;
	s = (char *)src;
	a = 0;
	if (!len || dst == src)
		return (dst);
	if ((unsigned char)src < (unsigned char)dst)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
