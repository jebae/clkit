/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_ndrange_kernel.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:28:56 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:28:56 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_enqueue_ndrange_kernel(\
	t_enqueue_ndrange_kernel_args *args)
{
	cl_int		ret;

	ret = clEnqueueNDRangeKernel(args->cmd_queue, args->kernel,\
		args->work_dim, NULL, args->global_work_size,\
		args->local_work_size, 0, NULL, NULL);
	return (clk_check_enqueue_ndrange_kernel(ret));
}
