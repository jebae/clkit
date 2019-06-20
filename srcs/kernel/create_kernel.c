/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_kernel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:35 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:35 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_create_kernel(cl_kernel *kernel,\
	cl_program program, const char *kernel_name)
{
	cl_int		ret;

	*kernel = clCreateKernel(program, kernel_name, &ret);
	return (clk_check_create_kernel(ret));
}
