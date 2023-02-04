/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:01:22 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/06 15:39:18 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_dir(char *tmp)
{
	tmp = getcwd(NULL, 0);
	if (tmp)
	{
		printf("%s\n", tmp);
		free(tmp);
		g_return = 0;
	}
	else
	{
		ft_putstrendl_fd("Error Occured!", 1);
		g_return = 127;
	}
}
