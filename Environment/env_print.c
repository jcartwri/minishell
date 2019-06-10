/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 20:46:50 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/28 20:46:52 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../d_minishell/minishell.h"

void	env_print(void)
{
	int i;

	i = 0;
	while (i < (int)g_env_value->size)
	{
		ft_printf("%s=%s\n", vector_get(g_env_key, i),
				vector_get(g_env_value, i));
		i++;
	}
}
