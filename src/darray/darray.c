/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 00:44:47 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/21 21:07:02 by imisumi-wsl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "darray.h"
#include "darray.h"

void	vec_clear(void *refvec)
{
	t_darray	*info;

	info = *(t_darray **)refvec - 1;
	info->count = 0;
}

void	vec_free(void *refvec)
{
	t_darray	*info;

	info = *(t_darray **)refvec - 1;
	free(info);
	*(void **)refvec = NULL;
}

int	vec_length(void *refvec)
{
	t_darray	*info;

	info = *(t_darray **)refvec - 1;
	return (info->count);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (malloc(size));
	if (!size)
		return (ptr);
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	return (new_ptr);
}

bool	vec_pushb(void *refvec, void *value)
{
	t_darray	*info;

	info = *(t_darray **)refvec - 1;
	if (info->count >= info->capacity)
	{
		info->capacity *= 2;
		info = ft_realloc(info, sizeof(t_darray) + (info->capacity * info->element_size));
		if (info == NULL)
		{
			vec_free(refvec);
			printf("Error: realloc failed\n");
			return (false);
		}
		vec_free(refvec);
		*(void **)refvec = info + 1;
	}
	ft_memcpy(
		*(char **)refvec + (info->count * info->element_size),
		value,
		info->element_size);
	info->count++;
	return (true);
}
