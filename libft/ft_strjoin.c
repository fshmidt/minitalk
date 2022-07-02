/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:51 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 00:21:35 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char *)malloc((size + 1) * sizeof(char));
	if (!(a))
		return (NULL);
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	size_t	b;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	b = ft_strlen(s1) + ft_strlen(s2);
	a = ft_strnew(b);
	if (!a)
		return (NULL);
	c = 0;
	while (s1[c])
	{
		a[c] = s1[c];
		c++;
	}
	b = 0;
	while (s2[b])
		a[c++] = s2[b++];
	a[c] = '\0';
	return (a);
}
