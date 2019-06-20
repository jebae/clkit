/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:53 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:54 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_check_create_kernel(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clCreateKernel ");
	if (ret == CL_INVALID_PROGRAM)
		return (clk_print_err("invalid program\n"));
	else if (ret == CL_INVALID_PROGRAM_EXECUTABLE)
		return (clk_print_err("invalid program executable\n"));
	else if (ret == CL_INVALID_KERNEL_NAME)
		return (clk_print_err("invalid kernel name\n"));
	else if (ret == CL_INVALID_KERNEL_DEFINITION)
		return (clk_print_err("invalid kernel definition\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}

int			clk_check_set_kernel_arg(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clSetKernelArg ");
	if (ret == CL_INVALID_KERNEL)
		return (clk_print_err("invalid kernel\n"));
	else if (ret == CL_INVALID_ARG_INDEX)
		return (clk_print_err("invalid arg index\n"));
	else if (ret == CL_INVALID_ARG_VALUE)
		return (clk_print_err("invalid arg value\n"));
	else if (ret == CL_INVALID_MEM_OBJECT)
		return (clk_print_err("invalid mem object\n"));
	else if (ret == CL_INVALID_SAMPLER)
		return (clk_print_err("invalid sampler\n"));
	else if (ret == CL_INVALID_ARG_SIZE)
		return (clk_print_err("invalid arg size\n"));
	return (CLKIT_SUCCESS);
}
