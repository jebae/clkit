/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:05 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:31:05 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_create_buffer(cl_mem *mem, t_create_buffer_args *args)
{
	cl_int		ret;

	*mem = clCreateBuffer(args->context, args->flags, args->size,\
		args->host_ptr, &ret);
	return (clk_check_create_buffer(ret));
}
