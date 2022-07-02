/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:58:45 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 02:34:22 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int		a;
	unsigned int		b;

	if (needle[0] == '\0')
		return ((char *)haystack);
	a = 0;
	while (haystack[a] && a < len)
	{
		b = 0;
		if (haystack[a] == needle[b])
		{
			while (a + b < len && haystack[a + b] == needle[b])
			{
				b++;
				if (!needle[b])
					return ((char *)&haystack[a]);
			}
		}
		a++;
	}
	return (0);
}
