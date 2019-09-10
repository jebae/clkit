/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cmd_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:58 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:35:23 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

static t_clk_cmd_queue		*allocate_cmd_queues(
	cl_uint num_devices
)
{
	t_clk_cmd_queue		*cmd_queues;
	cl_uint				i;

	cmd_queues = (t_clk_cmd_queue *)ft_memalloc(
		sizeof(t_clk_cmd_queue) * num_devices);
	if (cmd_queues == NULL)
	{
		clk_print_memalloc_err("command queues");
		return (NULL);
	}
	i = 0;
	while (i < num_devices)
		cmd_queues[i++].created = CLKIT_FALSE;
	return (cmd_queues);
}

int							clk_create_cmd_queues(t_clkit *clkit)
{
	cl_uint		i;
	cl_int		ret;

	clkit->cmd_queues = allocate_cmd_queues(clkit->num_devices);
	if (clkit->cmd_queues == NULL)
		return (CLKIT_FAIL);
	i = 0;
	while (i < clkit->num_devices)
	{
		clkit->cmd_queues[i].obj = clCreateCommandQueue(
			clkit->context.obj,
			clkit->devices[i],
			0,
			&ret
		);
		if (clk_check_create_cmd_queue(ret) == CLKIT_FAIL)
			return (CLKIT_FAIL);
		clkit->cmd_queues[i].created = CLKIT_TRUE;
		i++;
	}
	return (CLKIT_SUCCESS);
}
