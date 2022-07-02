/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:12:48 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 21:36:02 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	a;

	a = 0;
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		a++;
	}
	return (lst);
}
