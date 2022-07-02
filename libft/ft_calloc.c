/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:53:42 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:17:24 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	a;
	void	*cal;

	a = 0;
	cal = malloc(num * size);
	if (!cal)
		return (NULL);
	while (a < num * size)
		((unsigned char *)cal)[a++] = '\0';
	return (cal);
}
