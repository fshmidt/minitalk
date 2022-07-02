/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:56:31 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 15:20:29 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	a;

	a = 0;
	while (s[a])
	{
		if (s[a] == (char)c)
			return ((char *)(s + a));
		a++;
	}
	if (s[a] == (char)c)
		return ((char *)(s + a));
	return (NULL);
}
