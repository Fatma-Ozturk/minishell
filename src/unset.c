/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faozturk <faozturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:02:55 by faozturk          #+#    #+#             */
/*   Updated: 2022/12/08 17:39:25 by faozturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	unset(int var_pos, t_envp *s_envp)
{
	int	i;

	s_envp->env_len--;
	if (s_envp->envp[var_pos][0] != '\0')
		free(s_envp->envp[var_pos]);
	s_envp->envp[var_pos] = NULL;
	i = var_pos;
	while (s_envp->envp[i + 1])
	{
		s_envp->envp[i] = s_envp->envp[i + 1];
		s_envp->envp[i + 1] = NULL;
		i++;
	}
	realloc_envp(s_envp);
}

void	unset_handle(char *str, t_envp *s_envp)
{
	int		i;
	int		j;
	char	**s;
	char	*sub;
	int		len;

	len = ft_strlen(str);
	sub = ft_substr(str, 6, len - 6);
	s = ft_split(sub, ' ');
	i = -1;
	while (s[++i])
	{
		j = get_index(s[i], s_envp);
		if (s_envp->envp[j])
			unset(j, s_envp);
	}
	if (sub[0] != '\0')
		free(sub);
	if (s[0][0] != '\0')
		ft_free_str(s);
}
