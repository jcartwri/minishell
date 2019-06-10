/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:56:50 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/31 15:56:54 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		remove_new_line(char *buf, int col)
{
	if (buf[col - 1] && (buf[col - 1] == '\n' || buf[col - 1] == EOF))
	{
		buf[col - 1] = '\0';
		col = -1;
	}
	else
		buf[col] = '\0';
	return (col);
}

char	*lsh_read_line(void)
{
	char	buf[BUFF_SIZE + 1];
	char	*line;
	int		i;
	int		col;
	char	*str;

	i = 0;
	line = NULL;
	while ((col = read(0, buf, BUFF_SIZE)))
	{
		col = remove_new_line(buf, col);
		if (i == 0)
			line = ft_strdup(buf);
		else
		{
			str = line;
			line = ft_strjoin(line, buf);
			ft_strdel(&str);
		}
		if (col == -1)
			return (line);
		i = 1;
	}
	return (line);
}
