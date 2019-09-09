#include "clkit.h"

static void		release_kernels(cl_kernel *kernels, cl_uint num_kernels)
{
	cl_uint		i;

	i = 0;
	while (i < num_kernels)
		clReleaseKernel(kernels[i++]);
}

static void		release_mems(cl_mem *mems, cl_uint num_mems)
{
	cl_uint		i;

	i = 0;
	while (i < num_mems)
		clReleaseMemObject(mems[i++]);
}

static void		release_cmd_queues(cl_command_queue *cmd_queues,\
	cl_uint num_devices)
{
	cl_uint		i;

	i = 0;
	while (i < num_devices)
		clReleaseCommandQueue(cmd_queues[i++]);
}

void			clk_release_all(t_clkit *clkit)
{
	clReleaseProgram(clkit->program);
	clReleaseContext(clkit->context);
	if (clkit->devices != NULL)
		ft_memdel((void **)(&clkit->devices));
	if (clkit->cmd_queues != NULL)
	{
		release_cmd_queues(clkit->cmd_queues, clkit->num_devices);
		ft_memdel((void **)(&clkit->cmd_queues));
	}
	if (clkit->mems != NULL)
	{
		release_mems(clkit->mems, clkit->num_mems);
		ft_memdel((void **)(&clkit->mems));
	}
	if (clkit->kernels != NULL)
	{
		release_kernels(clkit->kernels, clkit->num_kernels);
		ft_memdel((void **)(&clkit->kernels));
	}
}
