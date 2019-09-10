/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:05 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:31:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

t_clk_mem	*clk_new_mems(cl_uint num_mems)
{
	t_clk_mem	*mems;
	cl_uint		i;

	mems = ft_memalloc(sizeof(t_clk_mem) * num_mems);
	if (mems == NULL)
	{
		clk_print_memalloc_err("mems");
		return (NULL);
	}
	i = 0;
	while (i < num_mems)
		mems[i++].created = CLKIT_FALSE;
	return (mems);
}

int			clk_create_buffer(t_clk_mem *mem, t_create_buffer_args *args)
{
	cl_int		ret;

	if (args->size == 0)
		return (CLKIT_FAIL);
	mem->obj = clCreateBuffer(
		args->context->obj,
		args->flags,
		args->size,
		args->host_ptr,
		&ret
	);
	if (clk_check_create_buffer(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	mem->created = CLKIT_TRUE;
	return (CLKIT_SUCCESS);
}
