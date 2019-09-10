/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:06 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:29:07 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int			clk_finish(t_clk_cmd_queue *cmd_queue)
{
	cl_int		ret;

	ret = clFinish(cmd_queue->obj);
	return (clk_check_finish(ret));
}
