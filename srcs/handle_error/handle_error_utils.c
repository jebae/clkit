/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:49 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:42:57 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

int		clk_print_err(const char *msg)
{
	put_color_str(KRED, msg);
	return (CLKIT_FAIL);
}

int		clk_print_memalloc_err(const char *target)
{
	clk_print_err("CLKIT : memalloc : Failed to allocate ");
	clk_print_err(target);
	ft_putchar('\n');
	return (CLKIT_FAIL);
}
