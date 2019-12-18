# clkit

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/1ad8ad3c010a4613a3eddf8d43d2f559)](https://www.codacy.com/manual/jebae/clkit?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=jebae/clkit&amp;utm_campaign=Badge_Grade)

:warning: **Using GPU not working with macOS >= 10.14**

<br>

**clkit** makes parallel programming with OpenCL more easier, including error handling from OpenCL API.

There are some constraints in clkit.

- Use only one **platform**
- Use only one **context**
- Use only one **program**

<br><br>

## Requirements

This library is using [libft](https://github.com/jebae/libft) as alternative of standard lib functions. So at first download or git clone [libft](https://github.com/jebae/libft) and put it in same path with clkit

```
# download libft
git clone https://github.com/jebae/libft.git

# directory structure of libft and clkit
root/
  libft/
  clkit/
```

instead of put libft in same path with clkit, you can modify [Makefile](Makefile) macro `LIBFT_PATH = ../libft` with your libft path.

<br><br>

## Installation

```c
make
```

<br><br>

## clkit struct

```c
typedef struct			s_clkit
{
	cl_platform_id		platform;
	cl_device_id		*devices;
	cl_uint			num_devices;
	t_clk_context		context;
	t_clk_cmd_queue		*cmd_queues;
	t_clk_mem		*mems;
	cl_uint			num_mems;
	t_clk_program		program;
	t_clk_kernel		*kernels;
	cl_uint			num_kernels;
}				t_clkit;
```

`devices`, `cmd_queues`, `mems`, `kernels` are pointer members. To use this members at first, you need to allocate memory. Allocating functions are prepared and will be presented below.

<br><br>

## Prerequisites

<br>

**1. Initialize clkit struct**
```c
void clk_init_clkit(t_clkit *clkit, cl_uint num_mems, cl_uint num_kernels);

// example
t_clkit clkit;

clk_init_clkit(&clkit, 2, 1);
```

`clk_init_clkit` initializes pointers in `clkit` as `NULL` and set `num_mems` and `num_kernels` with given parameters.

<br><br>

**2. Set plaform and device**

```c
int clk_set_device(t_clkit *clkit, cl_device_type type);

// example
t_clkit clkit;

clk_set_device(&clkit, CL_DEVICE_TYPE_GPU);
```

`clk_set_device` set `clkit.devices` with ids of device available.

Parameter `type` can be specific like `CL_DEVICE_TYPE_GPU` or `CL_DEVICE_TYPE_CPU`. In this case `clkit.num_devices` is set 1 and memory with `sizeof(cl_device_id) * 1` is allocated to `clkit.devices`.

If `type` is `CL_DEVICE_TYPE_ALL`, `clkit.num_devices` is set with number related with [clGetDeviceIDs](https://www.khronos.org/registry/OpenCL/sdk/1.0/docs/man/xhtml/clGetDeviceIDs.html). For example, if platform has 1 cpu and 1 gpu `clkit.num_devices` is set 2 and memory with `sizeof(cl_device_id) * 2` is allocated to `clkit.devices`.

It returns `CLKIT_FAIL` if there is error from memory allocating or OpenCL API, else `CLKIT_SUCCESS`.

<br>

```c
int clk_get_device_info(t_clkit *clkit);
```

`clk_get_device_info` shows device info like below. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

```
# output from clk_get_device_info
Device 0
Name Intel(R) Core(TM) i5-3470S CPU @ 2.90GHz
Device Version OpenCL 1.2
Driver Version 1.1
OpenCL C Version OpenCL C 1.2
Compute Units 4
Max Work Group Size 1024
```

<br><br>

**3. Create context and command queue**

```c
int clk_create_context(t_clkit *clkit);
```

`clk_create_context` set context object of OpenCL with `clkit.num_devices` and `clkit.devices`.

It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br>

```c
int clk_create_cmd_queues(t_clkit *clkit);
```

`clk_create_cmd_queues` set command queue object of OpenCL with `clkit.num_devices` and `clkit.devices`.

It returns `CLKIT_FAIL` if there is error from memory allocating or OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

**4. Create and build program**

```c
int clk_create_program(t_clk_program *program, t_clk_context *context, char *src);

// example
char *kernel_src = "\
  __kernel void get_unit_idx(__global int *out)\
  {\
    int idx = get_global_id(0);\
    out[idx] = idx;\
  }";
t_clkit clkit;

clk_create_program(&clkit.program, &clkit.context, kernel_src);
```
`clk_create_program` receives program, context pointer and kernel source. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br>

clkit prepared function `clk_concat_kernel_src` to concatenate kernel sources from multiple files.

```c
char *clk_concat_kernel_src(char **src_files, size_t num_files);
```
If lack of memory, it returns `NULL`. Returned value `char *` from `clk_concat_kernel_src` has to be deallocated by developer manually. 

<br>

```c
int clk_build_program(t_clk_program *program, cl_device_id *device);
```
`clk_build_program` build program created by `clk_create_program` on device received as parameter. If there is error during building (e.g. kernel source syntax error) log will be printed. It returns `CLKIT_FAIL` if there is error from memory allocating or OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

**5. Kernels**

```c
t_clk_kernel *clk_new_kernels(cl_uint num_kernels);
```

`clk_new_kernels` allocate memories for kernels and return memory address. If lack of memory, it returns `NULL`.

<br>

```c
int clk_create_kernel(t_clk_kernel *kernel, t_clk_program *program, const char *kernel_name);
```

`clk_create_kernel` create kernel object of OpenCL API with `kernel_name` received as parameter. Kernel with name `kernel_name` has to exist in your kernel sources. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

## Memory

```c
t_clk_mem *clk_new_mems(cl_uint num_mems);
```

`clk_new_mems` allocate memories for memory objects and return memory address. If lack of memory, it returns `NULL`.

<br>

```c
int clk_create_buffer(t_clk_mem *mem, t_create_buffer_args *args);

// example
t_clkit			clkit;
size_t			size = sizeof(char) * 128;
char			*buffer = ft_memalloc(size);
t_create_buffer_args	args;

args.context = &clkit.context;
args.flags = CL_MEM_WRITE_ONLY;
args.size = size;
args.host_ptr = buffer;

clkit.mems = clk_new_mems(1);
if (clkit.mems != NULL)
  clk_create_buffer(&clkit.mems[0], &args);
```

`clk_create_buffer` create memory object of OpenCL API. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

## Set kernel argument

```c
int clk_set_kernel_arg(
  t_clk_kernel *kernel,
  cl_uint arg_index,
  size_t arg_size,
  const void *arg_value
);

// example
/* kernel
__kernel void set_x(__global int *out, int x)
{
  int idx = get_global_id(0);

  out[idx] = x;
}
*/
int	x;
t_clkit	clkit;

x = 1;
clk_set_kernel_arg(&clkit.kernels[0], 0, sizeof(cl_mem), &clkit.mems[0].obj);
clk_set_kernel_arg(&clkit.kernels[0], 1, sizeof(int), x);
```

`clk_set_kernel_arg` receives arguments which gonna be used in kernel. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

## Executing command in queue

```c
int clk_enqueue_ndrange_kernel(t_enqueue_ndrange_kernel_args *args);

// example
t_clkit                         clkit;
t_enqueue_ndrange_kernel_args   args;

args.cmd_queue = clkit.cmd_queues[0];
args.kernel = clkit.kernels[0];
args.work_dim = /* work dimension for clEnqueueNDRangeKernel */;
args.global_work_size = /* global work size for clEnqueueNDRangeKernel */;
args.local_work_size = /* local work size for clEnqueueNDRangeKernel */;

clk_enqueue_ndrange_kernel(&args);

```

`clk_enqueue_ndrange_kernel` simply pass arguments to `clEnqueueNDRangeKernel` function. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br>

```c
int clk_enqueue_read_buffer(t_enqueue_buffer_args *args);

// example
t_clkit                   clkit;
t_enqueue_buffer_args     args;
int                       *host_buf;

args.cmd_queue = clkit.cmd_queues[0];
args.mem = clkit.mems[0];
args.offset = 0;
args.size = /* size for clEnqueueReadBuffer */;
args.host_buf = host_buf;
```

`clk_enqueue_read_buffer` simply pass arguments to `clEnqueueReadBuffer` function. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br>

```c
int clk_enqueue_write_buffer(t_enqueue_buffer_args *args);
```
`clk_enqueue_write_buffer` simply pass arguments to `clEnqueueWriteBuffer` function. It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br>

```c
int clk_flush(t_clk_cmd_queue *cmd_queue);
int clk_finish(t_clk_cmd_queue *cmd_queue);
```

`clk_flush` call `clFlush` with given `cmd_queue` parameter.
`clk_finish` call `clFinish` with given `cmd_queue` parameter.
It returns `CLKIT_FAIL` if there is error from OpenCL API, else `CLKIT_SUCCESS`.

<br><br>

## Release memories

```c
void clk_release_all(t_clkit *clkit);
```

`clk_release_all` release program, context, kernel, command queues, memory object of OpenCL API and free allocated memory in `clkit`.
