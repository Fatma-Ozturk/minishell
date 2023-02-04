/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:00:34 by faozturk          #+#    #+#             */
/*   Updated: 2022/09/23 18:00:39 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*check(char *s, int i)
{
	char	*tmp;
	int		j;

	j = 0;
	tmp = (char *)malloc(sizeof(char));
	while (s[i])
	{
		if (s[i] != '\'' && s[i] != '\"')
			tmp[j++] = s[i];
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

int	is_echo(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] == ' ')
		i++;
	tmp = check(s, i);
	i = 0;
	if ((tmp[i] == 'e' || tmp[i] == 'E') && (tmp[i + 1] == 'c'
			|| tmp[i + 1] == 'C')
		&& (tmp[i + 2] == 'h' || tmp[i + 2] == 'H') && (tmp[i + 3] == 'o'
			|| tmp[i + 3] == 'O'))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
