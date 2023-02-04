/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:00:24 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 16:42:06 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

void	ft_lstdelone(t_list *lst)
{
	free(lst->data);
	free(lst);
	lst = NULL;
}

void	ft_free_list(t_list **list)
{
	t_list	*tmp;

	if (list)
	{
		while (*list)
		{
			tmp = (*list)->next;
			ft_lstdelone(*list);
			*list = tmp;
		}
		free(list);
	}
}

void	ft_free_env(t_envp *s_envp)
{
	int	i;

	i = 0;
	while (s_envp->envp[i])
	{
		free(s_envp->envp[i]);
		i++;
	}
	free(s_envp);
	s_envp = NULL;
}
