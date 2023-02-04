/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:54:13 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/05 15:23:29 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *str)
{
	t_list	*root;

	root = (t_list *)malloc(sizeof(*root));
	if (root == NULL)
		return (NULL);
	root -> data = str;
	root -> next = NULL;
	return (root);
}
