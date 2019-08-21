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

static char		*handle_err(t_list **src_list, int fd, char *msg)
{
	if (fd != -1)
		close(fd);
	ft_lstdel(src_list, &del_str);
	clk_print_err("concat_kernel_src ");
	clk_print_err(msg);
	return (NULL);
}

static int		add_list(int fd, t_list **src_list, size_t *len_tot)
{
	t_list		*node;
	size_t		len;
	char		*src;

	src = get_file_content(fd);
	if (src == NULL)
		return (CLKIT_FAIL);
	len = ft_strlen(src);
	node = ft_lstnew((void *)src, sizeof(char) * (len + 1));
	if (node == NULL)
		return (CLKIT_FAIL);
	ft_lstadd(src_list, node);
	ft_memdel((void **)&src);
	*len_tot += len;
	return (CLKIT_SUCCESS);
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
			return (handle_err(&src_list, fd, "read file failed\n"));
		if (add_list(fd, &src_list, &len_tot) == CLKIT_FAIL)
			return (handle_err(&src_list, fd, "add list failed\n"));
		close(fd);
	}
	src = (char *)ft_memalloc(sizeof(char) * (len_tot + 1));
	if (src == NULL)
		return (NULL);
	ft_lstiter_with_arg(src_list, &iter_f, (void *)src);
	ft_lstdel(&src_list, &del_str);
	return (src);
}
