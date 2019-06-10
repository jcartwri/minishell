/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:10:29 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 20:10:32 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

void	env_unset(char *key)
{
	int i;

	i = 0;
	while (g_env_key->arr[i] != NULL)
	{
		if (ft_strcmp(key, g_env_key->arr[i]) == 0)
		{
			free(vector_get(g_env_key, i));
			g_env_key->arr[i] = NULL;
			vector_del(g_env_key, i);
			free(vector_get(g_env_value, i));
			g_env_value->arr[i] = NULL;
			vector_del(g_env_value, i);
			env_update();
			return ;
		}
		i++;
	}
	env_update();
}
