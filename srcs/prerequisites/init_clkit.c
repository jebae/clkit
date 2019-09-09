#include "clkit.h"

void		clk_init_clkit(
	t_clkit *clkit,
	cl_uint num_mems,
	cl_uint num_kernels
)
{
	clkit->num_mems = num_mems;
	clkit->num_kernels = num_kernels;
	clkit->devices = NULL;
	clkit->cmd_queues = NULL;
	clkit->mems = NULL;
	clkit->kernels = NULL;
}
