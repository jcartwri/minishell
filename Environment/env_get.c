/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:02:14 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 19:02:17 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

char	*env_get(char *key)
{
	char	*value;
	char	*str;
	int		i;

	i = 0;
	while ((str = vector_get(g_env_key, i)) != NULL)
	{
		if (ft_strcmp(str, key) == 0)
		{
			str = vector_get(g_env_value, i);
			value = ft_strdup(str);
			return (value);
		}
		i++;
	}
	return (ft_strdup(""));
}
