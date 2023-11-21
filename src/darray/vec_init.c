/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/21 21:05:18 by imisumi-wsl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "darray.h"

bool	vec_init(void *refvec, uint32_t capacity, size_t element_size)
{
	t_darray	*info;

	info = malloc(sizeof(t_darray) + (capacity * element_size));
	if (info == NULL)
	{
		ft_putstr_fd("Error: malloc failed\n", STDERR_FILENO);
		return (false);
	}
	*(void **)refvec = info + 1;
	info->capacity = capacity;
	info->count = 0;
	info->element_size = element_size;
	return (true);
}
