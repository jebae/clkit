/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:20 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:20 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_build_program(
	t_clk_program *program,
	cl_device_id *device
)
{
	cl_int		ret;

	ret = clBuildProgram(program->obj, 1, device, NULL, NULL, NULL);
	if (clk_check_build_program(ret) == CLKIT_SUCCESS)
		return (CLKIT_SUCCESS);
	clk_get_program_build_info(program->obj, *device);
	return (CLKIT_FAIL);
}
