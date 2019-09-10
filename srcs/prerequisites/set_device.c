/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_device.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:46 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:35:33 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

static int		allocate_devices(
	cl_device_id **devices,
	cl_uint num_devices
)
{
	*devices = (cl_device_id *)ft_memalloc(
		sizeof(cl_device_id) * num_devices);
	if (*devices == NULL)
		return (clk_print_memalloc_err("devices"));
	return (CLKIT_SUCCESS);
}

static int		set_gpu(t_clkit *clkit)
{
	cl_int		ret;

	clkit->num_devices = 1;
	if (allocate_devices(&(clkit->devices),
		clkit->num_devices) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	ret = clGetDeviceIDs(clkit->platform, CL_DEVICE_TYPE_GPU,
		clkit->num_devices, clkit->devices, NULL);
	return (clk_check_get_device_ids(ret));
}

static int		set_cpu(t_clkit *clkit)
{
	cl_int		ret;

	clkit->num_devices = 1;
	if (allocate_devices(&(clkit->devices),
		clkit->num_devices) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	ret = clGetDeviceIDs(clkit->platform, CL_DEVICE_TYPE_CPU,
		clkit->num_devices, clkit->devices, NULL);
	return (clk_check_get_device_ids(ret));
}

static int		set_all(t_clkit *clkit)
{
	cl_int		ret;

	ret = clGetDeviceIDs(clkit->platform, CL_DEVICE_TYPE_ALL,
		0, NULL, &(clkit->num_devices));
	if (clk_check_get_device_ids(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	if (allocate_devices(&(clkit->devices),
		clkit->num_devices) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	ret = clGetDeviceIDs(clkit->platform, CL_DEVICE_TYPE_ALL,
		clkit->num_devices, clkit->devices, NULL);
	return (clk_check_get_device_ids(ret));
}

int				clk_set_device(t_clkit *clkit, cl_device_type type)
{
	cl_int			ret;

	ret = clGetPlatformIDs(1, &(clkit->platform), NULL);
	if (clk_check_get_platform_ids(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	if (type == CL_DEVICE_TYPE_ALL)
		return (set_all(clkit));
	else if (type == CL_DEVICE_TYPE_GPU)
		return (set_gpu(clkit));
	else if (type == CL_DEVICE_TYPE_CPU)
		return (set_cpu(clkit));
	return (clk_print_err("CLKIT : set_device : wrong device type\n"));
}
