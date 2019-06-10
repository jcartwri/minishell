/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_deinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:34:04 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 20:34:05 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

void	delete_copy_env(void)
{
	int	i;

	i = 0;
	if (g_copy_env == NULL || g_copy_env[0] == NULL)
		return ;
	while (g_copy_env[i] != NULL)
	{
		ft_strdel(&g_copy_env[i]);
		i++;
	}
	ft_memdel((void **)&g_copy_env);
}

void	env_deinit(void)
{
	char	*str;

	delete_copy_env();
	while ((str = vector_get(g_env_key, 0)) != NULL)
	{
		ft_strdel(&str);
		vector_del(g_env_key, 0);
	}
	while ((str = vector_get(g_env_value, 0)) != NULL)
	{
		ft_strdel(&str);
		vector_del(g_env_value, 0);
	}
	vector_deinit(&g_env_key);
	vector_deinit(&g_env_value);
}
