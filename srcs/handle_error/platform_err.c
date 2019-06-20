/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platform_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:30:02 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:30:03 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int		clk_check_get_platform_ids(cl_int ret)
{
	if (ret == CL_INVALID_VALUE)
		return (clk_print_err("clGetPlatformIDs invalid value\n"));
	return (CLKIT_SUCCESS);
}
