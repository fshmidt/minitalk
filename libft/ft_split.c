/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:56:15 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/08 15:46:23 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_del(char **split, int *arr, int check)
{
	int	a;

	a = (check) / 2;
	while (a > 0)
		free(split[a--]);
	if (split[0] != NULL)
		free(split[0]);
	free(split);
	free(arr);
	return (NULL);
}

static int	ft_str_to_arr(char **split, const char *s, int *arr, int check)
{
	int	a;
	int	b;
	int	x;
	int	y;

	a = check / 2;
	b = 0;
	y = 0;
	while (a)
	{
		split[y] = (char *)malloc((arr[b + 1] - arr[b] + 2) * sizeof(char));
		if (!split[y])
			return (y);
		x = 0;
		while (arr[b + 1] - arr[b] + 1 - x)
		{
			split[y][x] = s[arr[b] + x];
			x++;
		}
		split[y++][x] = '\0';
		a--;
		b += 2;
	}
	split[y] = NULL;
	return (-1);
}

static int	*ft_wordnum_two(char const *s, char c, int *arr, int count)
{
	int	y;
	int	z;

	y = 0;
	z = 0;
	arr[2 * count] = -1;
	z = (int)ft_strlen(s);
	while (z > -1)
	{
		if (s[z - 1] != c && (s[z] == c || !s[z]) && 2 * count - y - 1 >= 0)
			arr[2 * count - y++ - 1] = z - 1;
		if ((s[z - 1] == c || !z) && s[z] != c && z + 1 <= (int)ft_strlen(s))
		{	
			arr[2 * count-- - y - 1] = z;
			y--;
		}
		z--;
	}
	return (arr);
}

static int	*ft_wordnum(char const *s, char c)
{
	int		z;
	int		count;
	int		*arr;

	z = 0;
	count = 0;
	while (s[z])
	{	
		if (s[z] != c && (s[z + 1] == c || !s[z + 1]))
			count++;
		z++;
	}
	arr = (int *)malloc((count * 2 + 1) * sizeof(int));
	if (!arr)
		return (NULL);
	return (ft_wordnum_two(s, c, arr, count));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		check;
	int		*arr;

	if (!s || (c < 0 || c > 127))
		return (NULL);
	arr = ft_wordnum(s, c);
	if (!arr)
		return (NULL);
	check = 0;
	while (arr[check] != -1)
	{
		if (arr[check++] == -1)
			break ;
	}
	split = malloc((check / 2 + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	check = ft_str_to_arr(split, s, arr, check);
	if (check != -1)
		return (ft_del(split, arr, check));
	free (arr);
	return (split);
}
