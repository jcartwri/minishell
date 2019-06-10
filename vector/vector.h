/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwalder- <rwalder-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:56:09 by rwalder-          #+#    #+#             */
/*   Updated: 2019/05/10 13:26:26 by rwalder-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_H
# define _VECTOR_H

# include <stdlib.h>

# define STACK_STEP 100
# if STACK_STEP < 1
#  error STACK_STEP must be >= 1
# endif
# define TYPE void*

typedef struct		s_vector
{
	TYPE			*arr;
	unsigned int	size;
}					t_vector;

t_vector			*vector_init(void);
int					vector_resize(t_vector *vector, unsigned int new_size);
int					vector_add(t_vector *vector, TYPE elem);
int					vector_del(t_vector *vector, unsigned int num);
int					vector_del_value(t_vector *vector, TYPE elem,
		unsigned int begin, unsigned int end);
TYPE				vector_get(t_vector *vector, unsigned int num);
int					vector_set(t_vector *vector, unsigned int num, TYPE elem);
long				vector_search(t_vector *vector, TYPE elem,
		unsigned int begin, unsigned int end);
void				vector_deinit(t_vector **vector);

#endif
