#include "clkit.h"

static void		release_kernels(
	t_clk_kernel *kernels,
	cl_uint num_kernels
)
{
	cl_uint		i;

	i = 0;
	while (i < num_kernels)
	{
		kernels[i].created && clReleaseKernel(kernels[i].obj);
		i++;
	}
}

static void		release_mems(
	t_clk_mem *mems,
	cl_uint num_mems
)
{
	cl_uint		i;

	i = 0;
	while (i < num_mems)
	{
		mems[i].created && clReleaseMemObject(mems[i].obj);
		i++;
	}
}

static void		release_cmd_queues(
	t_clk_cmd_queue *cmd_queues,
	cl_uint num_devices
)
{
	cl_uint		i;

	i = 0;
	while (i < num_devices)
	{
		cmd_queues[i].created && clReleaseCommandQueue(cmd_queues[i].obj);
		i++;
	}
}

void			clk_release_all(t_clkit *clkit)
{
	if (clkit->program.created)
		clReleaseProgram(clkit->program.obj);
	if (clkit->context.created)
		clReleaseContext(clkit->context.obj);
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
