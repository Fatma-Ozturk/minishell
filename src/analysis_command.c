/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:01:13 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 19:44:11 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	analysis_command(char *str, t_envp *s_envp)
{
	int	n_pipe;
	int	d_quote;
	int	s_quote;
	int	redir_out;
	int	redir_in;

	d_quote = count(str, '\"');
	s_quote = count(str, '\'');
	n_pipe = count(str, '|');
	redir_out = count(str, '>');
	redir_in = count(str, '<');
	if ((redir_out > 0 || redir_in > 0) && (d_quote == 0 && s_quote == 0))
		check_dir(str, s_envp);
	else if ((n_pipe > 0) && (redir_out == 0 && redir_in == 0))
		pipe_handle(str, n_pipe, s_envp);
	else if (is_builtin(str) > 0)
		exec_builtin(str, s_envp);
	else
		execsimple(str, s_envp);
}
