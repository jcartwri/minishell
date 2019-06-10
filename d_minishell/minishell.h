/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:40:26 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/31 17:40:35 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_MINISHELL_H
# define MINISHELL_MINISHELL_H
# define INIT {i = 0; y = 0; col = ft_count_tokens(line);}
# define DEL_0 {ft_strdel(&str); ft_mas_del(mas, 0, 0); ft_strdel(&path_file);}
# define R_DEL_1 {ft_strdel(&str); ft_mas_del(mas, fd, 1); return (path_file);}
# define STRDEL1 {ft_putendl_fd("lsh: command not found", 2); ft_strdel(&str);}
# define STRDEL {(STRDEL1); return (1);}

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../vector/vector.h"
# include "../ft_printf/libft/libft.h"
# include "../Environment/env.h"
# include "../ft_printf/libft/get_next_line.h"
# include "../ft_printf/ft_printf.h"

char		**g_copy_env;
t_vector	*g_env_key;
t_vector	*g_env_value;

void		ft_mas_del(char **mas, int fd, int flag);
int			ft_is_space(char c);
int			ft_count_tokens(char *line);
int			lsh_num_builtins();
int			lsh_echo(char **args);
int			lsh_cd(char **args);
int			lsh_exit(char **args);
int			lsh_help(char **args);
char		**lsh_split_line(char *line);
int			lsh_env(char **args);
int			lsh_setenv(char **args);
int			lsh_unsetenv(char **args);
char		*lsh_read_line(void);

#endif
