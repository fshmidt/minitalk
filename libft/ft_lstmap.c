/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbesan <mbesan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:02:02 by mbesan            #+#    #+#             */
/*   Updated: 2021/10/07 23:23:22 by mbesan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_second_part(t_list *lst, t_list *iteration, \
	void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_beg;

	new_beg = iteration;
	while (lst)
	{
		iteration = ft_lstnew(f(lst->content));
		if (!iteration)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&new_beg, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_beg, iteration);
	}
	return (new_beg);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iteration;

	if (!lst || !f)
		return (NULL);
	iteration = ft_lstnew(f(lst->content));
	if (!iteration)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst->next;
	return (ft_second_part(lst, iteration, f, del));
}
