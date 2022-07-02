/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:59:08 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/06 17:16:13 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(int c, char const *set)
{
	int	a;

	a = 0;
	while (set[a])
	{
		if (c == set[a++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	b;
	size_t	beginning;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	if (!ft_strlen(set))
		return (ft_strdup(s1));
	b = 0;
	beginning = 0;
	end = ft_strlen(s1);
	while (ft_isset(s1[beginning], set) && s1[beginning])
		beginning++;
	if (beginning == ft_strlen(s1) || !ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	while (ft_isset(s1[end - 1], set) && end)
		end--;
	a = malloc((end - beginning + 1) * sizeof(char));
	if (!a)
		return (NULL);
	while (beginning < end)
		a[b++] = s1[beginning++];
	a[b] = '\0';
	return (a);
}
