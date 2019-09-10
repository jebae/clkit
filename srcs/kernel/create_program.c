/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:38 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:38 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_create_program(
	t_clk_program *program,
	t_clk_context *context,
	char *src
)
{
	cl_int		ret;

	program->obj = clCreateProgramWithSource(
		context->obj,
		1,
		(const char **)&src,
		NULL,
		&ret
	);
	if (clk_check_create_program(ret) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	program->created = CLKIT_TRUE;
	return (CLKIT_SUCCESS);
}
