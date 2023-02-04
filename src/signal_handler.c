/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:02:42 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/09 10:28:37 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	handler_child(int signum)
{
	if (signum == SIGINT)
	{
		g_return = 130;
		write(1, "\n", 1);
	}
	if (signum == SIGQUIT)
	{
		g_return = 131;
		write(1, "\n", 1);
		ft_putstrendl_fd("Quit Child\n", 1);
	}
}

static void	handler_main(int signum)
{
	g_return = 130;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)signum;
}

void	signals(int signum)
{
	if (signum == 1)
	{
		signal(SIGINT, handler_main);
		signal(SIGQUIT, SIG_IGN);
	}
	if (signum == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
}
