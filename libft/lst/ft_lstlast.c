/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 19:09:05 by cluby             #+#    #+#             */
/*   Updated: 2023/11/22 12:28:41 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;
	int		last;
	int		i;

	temp = lst;
	last = ft_lstsize(temp) - 1;
	i = 0;
	while (i++ < last)
		temp = temp->next;
	return (temp);
}

/* int main()
{	
	t_list *head = ft_lstnew("test");
	t_list *node2 = ft_lstnew("test2");
	t_list *node3 = ft_lstnew("last");

	head->next = node2;
	node2->next = node3;
	ft_lstlast(head);
	return (0);
} */