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

static int		allocate_cmd_queues(
	cl_command_queue **cmd_queues,
	cl_uint num_devices
)
{
	*cmd_queues = (cl_command_queue *)ft_memalloc(
		sizeof(cl_command_queue) * num_devices);
	if (*cmd_queues == NULL)
		return (clk_print_memalloc_err("command queues"));
	return (CLKIT_SUCCESS);
}

int				clk_create_cmd_queues(t_clkit *clkit)
{
	cl_uint		i;
	cl_int		ret;

	if (allocate_cmd_queues(&(clkit->cmd_queues),\
		clkit->num_devices) == CLKIT_FAIL)
		return (CLKIT_FAIL);
	i = 0;
	while (i < clkit->num_devices)
	{
		clkit->cmd_queues[i] = clCreateCommandQueue(\
			clkit->context, clkit->devices[i], 0, &ret);
		if (clk_check_create_cmd_queue(ret) == CLKIT_FAIL)
			return (CLKIT_FAIL);
		i++;
	}
	return (CLKIT_SUCCESS);
}
