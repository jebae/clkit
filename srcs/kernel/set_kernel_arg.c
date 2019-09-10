/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_kernel_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:44 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:45 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_set_kernel_arg(
	t_clk_kernel *kernel,
	cl_uint arg_index,
	size_t arg_size,
	const void *arg_value
)
{
	cl_int		ret;

	ret = clSetKernelArg(kernel->obj, arg_index, arg_size, arg_value);
	return (clk_check_set_kernel_arg(ret));
}
