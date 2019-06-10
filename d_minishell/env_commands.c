/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:19:17 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/29 16:19:19 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	lsh_env(char **args)
{
	char *str1;
	char *str2;

	if (args[1] == NULL)
		env_print();
	else
	{
		str1 = ft_strjoin("env: ", args[1]);
		str2 = ft_strjoin(str1, " No such file or directory");
		ft_putendl_fd(str2, 2);
		ft_strdel(&str1);
		ft_strdel(&str2);
	}
	return (1);
}

int	lsh_setenv(char **args)
{
	if (args[1] == NULL)
	{
		ft_putendl_fd("lsh: ожидается аргумент", 2);
		return (1);
	}
	if (args[2] == NULL || ft_strcmp(args[2], "") == 0)
		env_set(args[1], "");
	else
		env_set(args[1], args[2]);
	return (1);
}

int	lsh_unsetenv(char **args)
{
	if (args[1] == NULL || ft_strcmp(args[1], "") == 0)
	{
		ft_putendl_fd("lsh: ожидается аргумент", 2);
		return (1);
	}
	env_unset(args[1]);
	return (1);
}
