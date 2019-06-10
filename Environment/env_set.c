/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:26:28 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 19:26:30 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

void	env_set(char *key, char *value)
{
	int		i;
	char	*str;

	i = 0;
	while ((str = vector_get(g_env_key, i)) != NULL)
	{
		if (ft_strcmp(str, key) == 0)
		{
			free(vector_get(g_env_value, i));
			vector_set(g_env_value, i, ft_strdup(value));
			env_update();
			return ;
		}
		i++;
	}
	vector_add(g_env_key, ft_strdup(key));
	vector_add(g_env_value, ft_strdup(value));
	env_update();
}
