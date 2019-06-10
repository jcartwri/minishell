/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 17:28:15 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/23 17:28:18 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "d_minishell/minishell.h"

char	*ft_find_pyth(char *pyth)
{
	char	**mas;
	char	*str;
	char	*path_file;
	int		fd;
	int		i;

	i = -1;
	path_file = env_get("PATH");
	if (ft_strcmp("", path_file) == 0)
	{
		ft_strdel(&path_file);
		return (ft_strdup(pyth));
	}
	mas = ft_strsplit(path_file, ':');
	ft_strdel(&path_file);
	str = ft_strjoin("/", pyth);
	while (mas && mas[++i])
	{
		path_file = ft_strjoin(mas[i], str);
		if ((fd = open(path_file, O_RDONLY)) != -1)
			(R_DEL_1);
		ft_strdel(&path_file);
	}
	(DEL_0);
	return (ft_strdup(pyth));
}

int		lsh_launch(char **args)
{
	pid_t	pid;
	char	*str;
	int		status;

	str = ft_find_pyth(args[0]);
	if (access(str, F_OK) == -1)
		(STRDEL);
	pid = fork();
	if (pid == 0)
	{
		if (execve(str, args, g_copy_env) == -1)
			ft_putendl_fd("lsh command not found", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putendl_fd("lsh command not found", 2);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	ft_strdel(&str);
	return (1);
}

int		lsh_execute(char **args)
{
	int			i;
	static int	(*builtin_func[]) (char **) = {&lsh_cd,
		&lsh_help,
		&lsh_exit,
		&lsh_echo,
		&lsh_env,
		&lsh_setenv,
		&lsh_unsetenv
	};
	const char	*builtin_str[] = { "cd",
		"help",
		"exit",
		"echo",
		"env",
		"setenv",
		"unsetenv"
	};

	if (args == NULL || args[0] == NULL)
		return (1);
	i = -1;
	while (++i < lsh_num_builtins())
		if (strcmp(args[0], builtin_str[i]) == 0)
			return (*builtin_func[i])(args);
	return (lsh_launch(args));
}

void	ft_replace(char **mas)
{
	int		i;
	char	*str;

	i = 0;
	if (mas == NULL)
		return ;
	while (mas[i])
	{
		if (mas[i][0] == '$')
		{
			str = env_get(mas[i] + 1);
			free(mas[i]);
			mas[i] = str;
		}
		else if (mas[i][0] == '~')
		{
			str = ft_strjoin("/Users/jcartwri", mas[i] + 1);
			free(mas[i]);
			mas[i] = str;
		}
		i++;
	}
}

int		main(void)
{
	char	*line;
	char	**args;
	int		status;
	int		i;

	env_init();
	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		line = lsh_read_line();
		args = lsh_split_line(line);
		ft_replace(args);
		status = lsh_execute(args);
		free(line);
		i = -1;
		while (args && args[++i])
			ft_strdel(&args[i]);
		free(args);
	}
	env_deinit();
	vector_deinit(&g_env_key);
	vector_deinit(&g_env_value);
	return (EXIT_SUCCESS);
}
