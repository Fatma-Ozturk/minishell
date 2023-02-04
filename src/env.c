/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:59:29 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 16:47:30 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_env(char **envp)
{
	int	i;

	i = -1;
	while (envp[++i] != NULL)
		ft_putstrendl_fd(envp[i], 1);
	g_return = 0;
}
