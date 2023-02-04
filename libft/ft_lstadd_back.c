/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:53:42 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/07 12:09:01 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		tmp = *lst;
	}
}
