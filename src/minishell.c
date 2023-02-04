/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:53:19 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/09 13:37:23 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	g_return;

int	is_path_exist(t_envp *s_envp)
{
	int	i;

	i = -1;
	while (s_envp->envp[++i])
	{
		if (ft_strncmp(s_envp->envp[i], "PATH=", 5) == 0)
			return (1);
	}
	return (0);
}

char	*takeinput(t_envp *s_envp)
{
	char	*str;
	char	*buf;

	str = "";
	buf = readline(">>>minishell ");
	if (!buf)
	{
		ft_putstr_fd("exit\n", 1);
		exit(130);
	}
	else if (is_path_exist(s_envp))
	{
		str = ft_strdup(buf);
		add_history(buf);
		free(buf);
		return (str);
	}
	ft_putstrendl_fd("Command Not Found", 1);
	if (buf[0] != '\0')
		free(buf);
	g_return = 127;
	return (str);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*str;
	t_envp	*s_envp;

	(void)argc;
	(void)argv;
	s_envp = init(envp);
	while (1)
	{
		signals(1);
		str = takeinput(s_envp);
		if (ft_strlen(str))
			analysis_command(str, s_envp);
		free(str);
	}
	ft_free_env(s_envp);
	return (0);
}
