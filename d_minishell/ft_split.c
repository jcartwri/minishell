/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:16:54 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/23 22:16:57 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_len_token(char *line, int i)
{
	int		j;
	char	str[7];

	ft_strcpy(str, " \t\r\n\a\"");
	j = 0;
	while (line[i + j] != '\0' && ft_strchr(str, line[i + j]) == '\0')
	{
		j++;
	}
	return (j);
}

char	*ft_get_token(char *line, int i)
{
	int		col;
	int		j;
	char	*str;

	j = 0;
	while (ft_is_space(line[i]) == 1)
		i++;
	col = ft_len_token(line, i);
	if (col == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (col + 1))))
	{
		ft_putendl_fd("lsh: ошибка выделения памяти\n", 2);
		exit(EXIT_FAILURE);
	}
	while (j < col)
	{
		str[j] = line[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		ft_check(char *line)
{
	int		i;
	char	str[7];

	ft_strcpy(str, " \t\r\n\a\"");
	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (ft_strchr(str, line[i]) == NULL)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	**lsh_split_line(char *line)
{
	char	**tokens;
	int		col;
	int		i;
	int		y;

	(INIT);
	if (ft_check(line) == 0)
		return (NULL);
	if (!(tokens = (char **)malloc(sizeof(char *) * (col + 1))))
	{
		ft_putendl_fd("lsh: ошибка выделения памяти", 2);
		exit(EXIT_FAILURE);
	}
	tokens[col] = NULL;
	while (line[i])
	{
		while (line[i] != '\0' && ft_is_space(line[i]) == 1)
			i++;
		if (line[i] == '\0')
			break ;
		col = ft_len_token(line, i);
		tokens[y++] = ft_get_token(line, i);
		i = i + col;
	}
	return (tokens);
}
