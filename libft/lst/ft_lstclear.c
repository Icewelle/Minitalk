/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:16:50 by cluby             #+#    #+#             */
/*   Updated: 2023/11/22 12:29:52 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *lst;
	while (temp1)
	{
		temp2 = temp1;
		del(temp1->content);
		temp1 = temp1->next;
		free(temp2);
	}
	*lst = NULL;
}
