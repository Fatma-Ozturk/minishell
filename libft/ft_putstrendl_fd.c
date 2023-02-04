/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrendl_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 17:55:17 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/05 15:24:14 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstrendl_fd(char *s, int fd)
{
	const char	nl = '\n';

	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}
