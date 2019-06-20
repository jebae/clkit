/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:56 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_check_create_buffer(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clCreateBuffer ");
	if (ret == CL_INVALID_CONTEXT)
		return (clk_print_err("invalid context\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	else if (ret == CL_INVALID_BUFFER_SIZE)
		return (clk_print_err("invalid buffer size\n"));
	else if (ret == CL_INVALID_HOST_PTR)
		return (clk_print_err("invalid host ptr\n"));
	else if (ret == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		return (clk_print_err("mem object allocation failed\n"));
	else if (ret == CL_OUT_OF_HOST_MEMORY)
		return (clk_print_err("out of host memory\n"));
	return (CLKIT_SUCCESS);
}
