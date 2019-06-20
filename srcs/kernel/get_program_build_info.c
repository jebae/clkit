/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program_build_info.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:41 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:42 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_get_program_build_info(cl_program program,\
	cl_device_id device)
{
	cl_int		ret;
	size_t		value_size;
	char		*log;

	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, 0, NULL, &value_size);
	if (clk_check_get_program_build_info(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, 0, NULL, &value_size);
	if (clk_check_get_program_build_info(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	log = (char *)ft_memalloc(sizeof(char) * value_size);
	ret = clGetProgramBuildInfo(program, device,\
		CL_PROGRAM_BUILD_LOG, value_size, log, NULL);
	if (ft_strlen(log) > 0)
		clk_print_err(log);
	ft_memdel((void **)&log);
	return (clk_check_get_program_build_info(ret));
}
