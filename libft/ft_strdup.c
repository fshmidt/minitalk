/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:57:01 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:17:32 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		a;

	if (s[0] != '\0')
		copy = malloc(ft_strlen(s) + 1 * sizeof(char));
	else
		copy = malloc(sizeof(char));
	if (copy == NULL)
		return (NULL);
	a = 0;
	while (s[a])
	{
		copy[a] = s[a];
		++a;
	}
	copy[a] = '\0';
	return (copy);
}
