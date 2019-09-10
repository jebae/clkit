/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clkit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebae <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 16:59:45 by jebae             #+#    #+#             */
/*   Updated: 2019/09/09 17:32:36 by jebae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLKIT_H
# define CLKIT_H

# include <OpenCL/cl.h>
# include <fcntl.h>
# include "libft.h"

# define CLKIT_SUCCESS			1
# define CLKIT_FAIL				0
# define CLKIT_TRUE				1
# define CLKIT_FALSE			0

typedef struct			s_clk_context
{
	cl_context			obj;
	cl_int				created;
}						t_clk_context;

typedef struct			s_clk_cmd_queue
{
	cl_command_queue	obj;
	cl_int				created;
}						t_clk_cmd_queue;

typedef struct			s_clk_mem
{
	cl_mem				obj;
	cl_int				created;
}						t_clk_mem;

typedef struct			s_clk_program
{
	cl_program			obj;
	cl_int				created;
}						t_clk_program;

typedef struct			s_clk_kernel
{
	cl_kernel			obj;
	cl_int				created;
}						t_clk_kernel;

typedef struct			s_clkit
{
	cl_platform_id		platform;
	cl_device_id		*devices;
	cl_uint				num_devices;
	t_clk_context		context;
	t_clk_cmd_queue		*cmd_queues;
	t_clk_mem			*mems;
	cl_uint				num_mems;
	t_clk_program		program;
	t_clk_kernel		*kernels;
	cl_uint				num_kernels;
}						t_clkit;

typedef struct			s_create_buffer_args
{
	t_clk_context		*context;
	cl_mem_flags		flags;
	size_t				size;
	void				*host_ptr;
}						t_create_buffer_args;

typedef struct			s_enqueue_ndrange_kernel_args
{
	t_clk_cmd_queue		*cmd_queue;
	t_clk_kernel		*kernel;
	cl_uint				work_dim;
	const size_t		*global_work_size;
	const size_t		*local_work_size;
}						t_enqueue_ndrange_kernel_args;

typedef struct			s_enqueue_buffer_args
{
	t_clk_cmd_queue		*cmd_queue;
	t_clk_mem			*mem;
	size_t				offset;
	size_t				size;
	void				*host_buf;
}						t_enqueue_buffer_args;

/*
** handle_error
*/
int						clk_print_err(const char *msg);
int						clk_print_memalloc_err(const char *target);
int						clk_check_get_platform_ids(cl_int ret);
int						clk_check_get_device_ids(cl_int ret);
int						clk_check_get_device_info(cl_int ret);
int						clk_check_create_context(cl_int ret);
int						clk_check_create_cmd_queue(cl_int ret);
int						clk_check_create_buffer(cl_int ret);
int						clk_check_create_program(cl_int ret);
int						clk_check_build_program(cl_int ret);
int						clk_check_get_program_build_info(cl_int ret);
int						clk_check_create_kernel(cl_int ret);
int						clk_check_set_kernel_arg(cl_int ret);
int						clk_check_enqueue_ndrange_kernel(cl_int ret);
int						clk_check_enqueue_read_buffer(cl_int ret);
int						clk_check_enqueue_write_buffer(cl_int ret);
int						clk_check_flush(cl_int ret);
int						clk_check_finish(cl_int ret);
int						clk_check_release_kernel(cl_int ret);
int						clk_check_release_program(cl_int ret);
int						clk_check_release_mem_object(cl_int ret);
int						clk_check_release_cmd_queue(cl_int ret);
int						clk_check_release_context(cl_int ret);

/*
** prerequisites
*/
void					clk_init_clkit(
	t_clkit *clkit,
	cl_uint num_mems,
	cl_uint num_kernels
);

int						clk_set_device(
	t_clkit *clkit,
	cl_device_type type
);

int						clk_create_context(t_clkit *clkit);

int						clk_create_cmd_queues(t_clkit *clkit);

int						clk_get_device_info(t_clkit *clkit);

/*
** memory
*/
t_clk_mem				*clk_new_mems(cl_uint num_mems);

int						clk_create_buffer(
	t_clk_mem *mem,
	t_create_buffer_args *args
);

/*
** kernel
*/
int						clk_create_program(
	t_clk_program *program,
	t_clk_context *context,
	char *src
);

int						clk_build_program(
	t_clk_program *program,
	cl_device_id *device
);

int						clk_get_program_build_info(
	cl_program program,
	cl_device_id device
);

t_clk_kernel			*clk_new_kernels(cl_uint num_kernels);

int						clk_create_kernel(
	t_clk_kernel *kernel,
	t_clk_program *program,
	const char *kernel_name
);

int						clk_set_kernel_arg(
	t_clk_kernel *kernel,
	cl_uint arg_index,
	size_t arg_size,
	const void *arg_value
);

char					*clk_concat_kernel_src(
	char **src_files,
	size_t num_files
);

/*
** cmd_queue
*/
int						clk_enqueue_ndrange_kernel(
	t_enqueue_ndrange_kernel_args *args
);

int						clk_enqueue_read_buffer(
	t_enqueue_buffer_args *args
);

int						clk_enqueue_write_buffer(
	t_enqueue_buffer_args *args
);

int						clk_finish(t_clk_cmd_queue *cmd_queue);

int						clk_flush(t_clk_cmd_queue *cmd_queue);

/*
** release
*/
void					clk_release_all(t_clkit *clkit);

#endif
