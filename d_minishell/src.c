/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 18:07:21 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/31 18:07:23 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' ||
		c == '\r' || c == '\a' || c == '\"')
	{
		return (1);
	}
	return (0);
}

int		ft_count_tokens(char *line)
{
	int		i;
	int		flag;
	int		col;
	char	str[7];

	ft_strcpy(str, " \t\r\n\a\"");
	i = -1;
	col = 0;
	flag = 0;
	if (!line)
		return (0);
	while (line[++i])
	{
		if (ft_strchr(str, line[i]) != '\0')
		{
			if (flag < 0)
				col++;
			flag = (flag >= 0) ? flag + 1 : flag * (-1) + 1;
		}
		else
			flag = (flag <= 0) ? flag - 1 : flag * (-1) - 1;
	}
	if (flag < 0)
		col++;
	return (col);
}

void	ft_mas_del(char **mas, int fd, int flag)
{
	int	i;

	i = -1;
	while (mas && mas[++i])
		ft_strdel(&mas[i]);
	free(mas);
	if (flag == 1)
	{
		close(fd);
	}
}
