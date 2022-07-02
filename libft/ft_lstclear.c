/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:53:27 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 21:35:34 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*a;

	if (!del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		a = *lst;
		*lst = a->next;
		free(a);
	}
	*lst = NULL;
}
