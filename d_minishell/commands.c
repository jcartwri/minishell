/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:28:04 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/23 17:28:07 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	g_path[100];

int		lsh_num_builtins(void)
{
	const char	*builtin_str[] = {
		"cd",
		"help",
		"exit",
		"echo",
		"env",
		"setenv",
		"unsetenv"
	};

	return (sizeof(builtin_str) / sizeof(char *));
}

int		lsh_cd(char **args)
{
	if (!args[1] || ft_strcmp(args[1], "-") != 0)
		getcwd(g_path, 100);
	if (args[1] == NULL)
	{
		if (chdir("/Users/jcartwri") != 0)
			ft_putendl_fd("lsh: No such file or directory", 2);
		return (1);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (g_path[0] == '\0')
			ft_putstr("~\n");
		else
		{
			ft_printf("%s%s\n", "~", g_path);
			chdir(g_path);
			getcwd(g_path, 100);
		}
	}
	else if (chdir(args[1]) != 0)
		ft_putendl_fd("lsh: No such file or directory", 2);
	return (1);
}

int		lsh_help(char **args)
{
	int			i;
	const char	*builtin_str[] = {
		"cd",
		"help",
		"exit",
		"echo",
		"env",
		"setenv",
		"unsetenv"
	};

	(void)args;
	ft_printf("LSH jcartwri\n");
	ft_printf("Наберите название программы и её аргументы и нажмите enter.\n");
	ft_printf("Вот список втсроенных команд:\n");
	i = -1;
	while (++i < lsh_num_builtins())
		ft_printf("  %s\n", builtin_str[i]);
	ft_printf("Используйте команду man для получения"
		"информации по другим программам.\n");
	return (1);
}

int		lsh_exit(char **args)
{
	(void)args;
	return (0);
}

int		lsh_echo(char **args)
{
	int i;

	i = 1;
	if (args[1])
		i = (ft_strcmp(args[1], "-n") == 0) ? 2 : 1;
	if ((i == 1 && args[1] == NULL) || (i == 2 && args[2] == NULL))
	{
		if (i == 1)
			ft_putchar('\n');
		return (1);
	}
	while (args[i])
	{
		ft_putstr(args[i++]);
		if (args[i] != NULL)
			ft_putchar(' ');
	}
	if (args[1] != NULL && ft_strcmp(args[1], "-n") == 0)
		return (1);
	else
		ft_putchar('\n');
	return (1);
}
