/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:55:21 by rwalder-          #+#    #+#             */
/*   Updated: 2019/05/10 13:26:26 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_init(void)
{
	t_vector	*ret;
	int			i;

	if ((ret = (t_vector*)malloc(sizeof(t_vector))) == NULL)
		return (NULL);
	if ((ret->arr = (TYPE*)malloc(sizeof(TYPE) * STACK_STEP)) == NULL)
	{
		free(ret);
		return (NULL);
	}
	i = 0;
	while (i < STACK_STEP)
		ret->arr[i++] = NULL;
	ret->size = 0;
	return (ret);
}
