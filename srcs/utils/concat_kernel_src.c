/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_kernel_src.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:32:24 by jebae             #+#    #+#             */
/*   Updated: 2019/06/17 14:32:25 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "clkit.h"

static void		del_str(void *content, size_t content_size)
{
	ft_memdel((void **)&content);
	content_size = 0;
}

static void		iter_f(t_list *elem, void *arg)
{
	ft_strcat((char *)arg, (char *)(elem->content));
}

static char		*handle_file_err(t_list **src_list)
{
	ft_lstdel(src_list, &del_str);
	clk_print_err("concat_kernel_src file read failed\n");
	return (NULL);
}

static void		add_list(int fd, t_list **src_list, size_t *len_tot)
{
	t_list		*node;
	size_t		len;
	char		*src;

	src = get_file_content(fd);
	len = ft_strlen(src);
	node = ft_lstnew((void *)src, sizeof(char) * (len + 1));
	ft_lstadd(src_list, node);
	ft_memdel((void **)&src);
	*len_tot += len;
}

char			*clk_concat_kernel_src(char **src_files, size_t num_files)
{
	int			fd;
	size_t		len_tot;
	char		*src;
	t_list		*src_list;

	if (num_files == 0)
		return (NULL);
	len_tot = 0;
	src_list = NULL;
	while (num_files--)
	{
		fd = open(src_files[num_files], O_RDONLY);
		if (fd == -1)
			return (handle_file_err(&src_list));
		add_list(fd, &src_list, &len_tot);
		close(fd);
	}
	src = (char *)ft_memalloc(sizeof(char) * (len_tot + 1));
	ft_lstiter_with_arg(src_list, &iter_f, (void *)src);
	ft_lstdel(&src_list, &del_str);
	return (src);
}
