/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:32:10 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:32:10 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

static void		release_kernels(cl_kernel *kernels, cl_uint num_kernels)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_kernels)
	{
		ret = clReleaseKernel(kernels[i]);
		clk_check_release_kernel(ret);
		i++;
	}
}

static void		release_mems(cl_mem *mems, cl_uint num_mems)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_mems)
	{
		ret = clReleaseMemObject(mems[i]);
		clk_check_release_mem_object(ret);
		i++;
	}
}

static void		release_cmd_queues(cl_command_queue *cmd_queues,\
	cl_uint num_devices)
{
	cl_int		ret;
	cl_uint		i;

	i = 0;
	while (i < num_devices)
	{
		ret = clReleaseCommandQueue(cmd_queues[i]);
		clk_check_release_cmd_queue(ret);
		i++;
	}
}

void			clk_release_all(t_clkit *clkit,\
	cl_uint num_kernels, cl_uint num_mems)
{
	cl_int		ret;

	release_kernels(clkit->kernels, num_kernels);
	ret = clReleaseProgram(clkit->program);
	clk_check_release_program(ret);
	release_mems(clkit->mems, num_mems);
	release_cmd_queues(clkit->cmd_queues, clkit->num_devices);
	ret = clReleaseContext(clkit->context);
	clk_check_release_context(ret);
}

void			clk_free_all(t_clkit *clkit)
{
	ft_memdel((void **)(&clkit->devices));
	ft_memdel((void **)(&clkit->cmd_queues));
	ft_memdel((void **)(&clkit->mems));
	ft_memdel((void **)(&clkit->kernels));
}
