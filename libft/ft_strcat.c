/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:56:21 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:12:24 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[g] != '\0')
	{
		dest[i] = src[g];
		i++;
		g++;
	}
	dest[i] = '\0';
	return (dest);
}
