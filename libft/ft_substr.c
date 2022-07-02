/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:59:13 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 14:09:29 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	if (s == NULL)
		return (NULL);
	a = ft_strlen(s);
	if (a <= start || !s[0] || !len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > a)
		len = a - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	a = 0;
	while (a < len)
		str[a++] = s[start++];
	str[a] = '\0';
	return (str);
}
