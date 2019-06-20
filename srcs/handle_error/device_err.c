/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:46 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:46 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_check_get_device_ids(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clGetDeviceIDs ");
	if (ret == CL_INVALID_PLATFORM)
		return (clk_print_err("invalid platform\n"));
	else if (ret == CL_INVALID_DEVICE_TYPE)
		return (clk_print_err("invalid device type\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	else if (ret == CL_DEVICE_NOT_FOUND)
		return (clk_print_err("device not found\n"));
	return (CLKIT_SUCCESS);
}

int			clk_check_get_device_info(cl_int ret)
{
	if (ret != CL_SUCCESS)
		clk_print_err("clGetDeviceInfo ");
	if (ret == CL_INVALID_DEVICE)
		return (clk_print_err("invalid device\n"));
	else if (ret == CL_INVALID_VALUE)
		return (clk_print_err("invalid value\n"));
	return (CLKIT_SUCCESS);
}
