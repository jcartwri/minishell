/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:49:22 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 19:49:24 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

static void	delete(void)
{
	unsigned int i;

	i = 0;
	if (g_copy_env == NULL)
		return ;
	while (g_copy_env[i] != NULL)
		ft_strdel(&(g_copy_env[i++]));
	ft_memdel((void**)&g_copy_env);
}

static char	*join(unsigned int i)
{
	char *ret;
	char *temp;

	temp = ft_strjoin("=", g_env_value->arr[i]);
	ret = ft_strjoin(g_env_key->arr[i], temp);
	ft_strdel(&temp);
	return (ret);
}

void		env_update(void)
{
	unsigned int i;

	delete();
	g_copy_env = (char**)ft_memalloc(sizeof(char*) * (g_env_key->size + 1));
	if (g_copy_env == NULL)
		exit(-1);
	i = 0;
	while (i < g_env_key->size)
	{
		g_copy_env[i] = join(i);
		i++;
	}
	g_copy_env[i] = NULL;
}
