/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:55 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:06:00 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_length;
	size_t	res;

	d_length = ft_strlen(dst);
	if (dstsize < d_length)
		res = dstsize + ft_strlen(src);
	else
		res = d_length + ft_strlen(src);
	if (dstsize > d_length)
	{
		dst += d_length;
		dstsize -= d_length;
		while (*src && dstsize-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (res);
}
