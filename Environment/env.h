/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 17:54:30 by jcartwri          #+#    #+#             */
/*   Updated: 2019/05/31 17:54:32 by jcartwri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENV_H
# define MINISHELL_ENV_H

int		env_init(void);
void	env_set(char *key, char *value);
void	env_update(void);
char	*env_get(char *key);
void	env_unset(char	*key);
void	env_deinit(void);
void	env_print(void);

#endif
