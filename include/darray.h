/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/21 21:05:05 by imisumi-wsl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DARRAY_H
# define DARRAY_H

# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# include "libft.h"

typedef struct s_darray
{
	uint32_t	capacity;
	uint32_t	count;
	size_t		element_size;
}				t_darray;

bool	vec_init(void *refvec, uint32_t capacity, size_t element_size);
bool	vec_pushb(void *refvec, void *value);
void	vec_clear(void *refvec);
void	vec_free(void *refvec);
int		vec_length(void *refvec);

#endif
