/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_kernel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:35 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 14:20:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

t_clk_kernel	*clk_new_kernels(cl_uint num_kernels)
{
	t_clk_kernel	*kernels;
	cl_uint			i;

	kernels = ft_memalloc(sizeof(t_clk_kernel) * num_kernels);
	if (kernels == NULL)
	{
		clk_print_memalloc_err("kernels");
		return (NULL);
	}
	i = 0;
	while (i < num_kernels)
		kernels[i++].created = CLKIT_FALSE;
	return (kernels);
}

int				clk_create_kernel(
	t_clk_kernel *kernel,
	t_clk_program *program,
	const char *kernel_name
)
{
	cl_int		ret;

	kernel->obj = clCreateKernel(program->obj, kernel_name, &ret);
	if (clk_check_create_kernel(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	kernel->created = CLKIT_TRUE;
	return (CLKIT_SUCCESS);
}
