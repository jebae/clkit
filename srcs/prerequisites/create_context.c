/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_context.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:31:49 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 14:26:04 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_create_context(t_clkit *clkit)
{
	cl_int		ret;

	clkit->context = clCreateContext(NULL, clkit->num_devices,
		clkit->devices, NULL, NULL, &ret);
	return (clk_check_create_context(ret));
}
