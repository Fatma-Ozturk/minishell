/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:52:57 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/09 11:52:59 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	**add_list(char **str, t_list **mini)
{
	int		i;
	char	*temp;
	t_list	*temp2;

	i = 0;
	while (str[i])
	{
		temp = ft_strtrim(str[i], " ");
		temp2 = ft_lstnew(temp);
		ft_lstadd_back(mini, temp2);
		temp = NULL;
		temp2 = NULL;
		i++;
	}
	free (temp);
	free (temp2);
	return (mini);
}
