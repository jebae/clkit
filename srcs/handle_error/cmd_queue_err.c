/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_queue_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:25 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:26 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_check_create_cmd_queue(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clCreateCommandQueue ");
	if (ret == CL_INVALID_CONTEXT)
		return (clk_print_err("invalid context\n"));
	else if (ret == CL_INVALID_DEVICE)
		return (clk_print_err("invalid device\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	else if (ret == CL_INVALID_QUEUE_PROPERTIES)
		return (clk_print_err("invalud queue properties\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}

int			clk_check_enqueue_read_buffer(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clEnqueueReadBuffer ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clk_print_err("invalid command queue\n"));
	else if (ret == CL_INVALID_CONTEXT)
		return (clk_print_err("invalid context\n"));
	else if (ret == CL_INVALID_MEM_OBJECT)
		return (clk_print_err("invalid mem object\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	else if (ret == CL_INVALID_EVENT_WAIT_LIST)
		return (clk_print_err("invalid event wait list\n"));
	else if (ret == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		return (clk_print_err("mem object allocation failed\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}

static int	clk_check_enqueue_ndrange_kernel2(cl_int ret)
{
	if (ret == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		return (clk_print_err("mem object allocation failed\n"));
	else if (ret == CL_INVALID_EVENT_WAIT_LIST)
		return (clk_print_err("invalid event wait list\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}

int			clk_check_enqueue_ndrange_kernel(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clEnqueueNDRangeKernel ");
	if (ret == CL_INVALID_PROGRAM_EXECUTABLE)
		return (clk_print_err("invalid program executable\n"));
	else if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clk_print_err("invalid command queue\n"));
	else if (ret == CL_INVALID_KERNEL)
		return (clk_print_err("invalid kernel\n"));
	else if (ret == CL_INVALID_CONTEXT)
		return (clk_print_err("invalid context\n"));
	else if (ret == CL_INVALID_KERNEL_ARGS)
		return (clk_print_err("invalid kernel args\n"));
	else if (ret == CL_INVALID_WORK_DIMENSION)
		return (clk_print_err("invalid work dimension\n"));
	else if (ret == CL_INVALID_WORK_GROUP_SIZE)
		return (clk_print_err("invalid work group size\n"));
	else if (ret == CL_INVALID_WORK_ITEM_SIZE)
		return (clk_print_err("invalid work item size\n"));
	else if (ret == CL_INVALID_GLOBAL_OFFSET)
		return (clk_print_err("invalid global offset\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clk_print_err("out of resources\n"));
	return (clk_check_enqueue_ndrange_kernel2(ret));
}

int			clk_check_flush(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clFlush ");
	if (ret == CL_INVALID_COMMAND_QUEUE)
		return (clk_print_err("invalid command queue\n"));
	else if (ret == CL_OUT_OF_RESOURCES)
		return (clk_print_err("out of resources\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}
