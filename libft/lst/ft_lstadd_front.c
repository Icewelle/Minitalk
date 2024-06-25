/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:48:52 by cluby             #+#    #+#             */
/*   Updated: 2023/11/05 17:24:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst || new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* int main()
{
	t_list *head = ft_lstnew("test");
	t_list *node2 = ft_lstnew("test2");
	t_list *node3 = ft_lstnew("head");

	head->next = node2;
	ft_lstadd_front(&head, node3);
	printf("%s\n", (char*)head->content);
	return (0);
} */
