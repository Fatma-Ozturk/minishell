/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:29 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/05 15:26:21 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_cd(char *tmp)
{
	char	*sub;
	int		len;

	len = ft_strlen(tmp);
	sub = ft_substr(tmp, 3, len - 3);
	if (sub[0] == '\0' || sub[0] == '~')
	{
		sub = ft_strdup(getenv("HOME"));
	}
	g_return = chdir(sub);
	free(sub);
	if (g_return < 0)
		ft_putstrendl_fd("cd: no such file or directory", 1);
}
