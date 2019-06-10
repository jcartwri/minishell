/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 17:01:57 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 17:02:00 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

int		env_init(void)
{
	unsigned int	i;
	char			**env;
	extern char		**environ;

	env = NULL;
	g_env_key = vector_init();
	g_env_value = vector_init();
	i = 0;
	while (environ[i] != NULL)
	{
		if ((env = ft_strsplit(environ[i], '=')) == NULL)
			exit(-1);
		vector_add(g_env_key, env[0]);
		if (env[1])
			vector_add(g_env_value, env[1]);
		else
			vector_add(g_env_value, ft_strdup(""));
		free(env);
		i++;
	}
	g_copy_env = NULL;
	env_update();
	return (1);
}
