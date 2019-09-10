/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue_write_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:01 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:02 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_enqueue_write_buffer(t_enqueue_buffer_args *args)
{
	cl_int		ret;

	ret = clEnqueueWriteBuffer(
		args->cmd_queue->obj,
		args->mem->obj,
		CL_TRUE,
		args->offset,
		args->size,
		args->host_buf,
		0, NULL, NULL
	);
	return (clk_check_enqueue_write_buffer(ret));
}
