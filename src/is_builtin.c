/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:00:44 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 20:40:54 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(char *tmp)
{
	if (!tmp)
		return (0);
	if (is_echo(tmp))
		return (1);
	else if (!ft_strncmp(tmp, "cd", 2))
		return (2);
	else if (!ft_strncmp(tmp, "pwd", 3))
		return (3);
	else if (!ft_strncmp(tmp, "export", 6))
		return (4);
	else if (!ft_strncmp(tmp, "unset", 5))
		return (5);
	else if (!ft_strcmp(tmp, "env"))
	{
		g_return = 127;
		return (6);
	}
	else if (!ft_strncmp(tmp, "exit", 4))
		return (7);
	return (0);
}

void	exec_builtin(char *str, t_envp *s_envp)
{
	char	*tmp;
	int		i;

	tmp = ft_strtrim(str, " ");
	i = is_builtin(tmp);
	if (i == 1)
		echo_canalizer(str, s_envp);
	else if (i == 2)
		mini_cd(tmp);
	else if (i == 3)
		print_dir(tmp);
	else if (i == 4)
		export_handle(tmp, s_envp);
	else if (i == 5)
		unset_handle(tmp, s_envp);
	else if (i == 6)
		print_env(s_envp->envp);
	else if (i == 7)
		exit(0);
	free (tmp);
}
