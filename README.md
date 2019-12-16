# clkit

**clkit** makes parallel programming with OpenCL more easier, including error handling from OpenCL API.

There are some constraints in clkit.

- Use only one **platform**
- Use only one **context**
- Use only one **program**

<br><br>

## How to use

### requirements

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

### clkit struct

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

### prerequisites

<br>

**1. Initialize clkit struct**
```c
void clk_init_clkit(
  t_clkit *clkit,
  cl_uint num_mems,
  cl_uint num_kernels
);

// example
t_clkit clkit;

clk_init_clkit(&clkit, 2, 1);
```

`clk_init_clkit` initializes pointers in `clkit` as `NULL` and set `num_mems` and `num_kernels` with given parameters.

<br><br>

**2. Set plaform and device**

```c
int clk_set_device(
  t_clkit *clkit,
  cl_device_type type
);

// example
t_clkit clkit;

clk_set_device(&clkit, CL_DEVICE_TYPE_GPU);
```

`clk_set_device` set `clkit.devices` with ids of device available.

Parameter `type` can be specific like `CL_DEVICE_TYPE_GPU` or `CL_DEVICE_TYPE_CPU`. In this case `clkit.num_devices` is set 1 and memory with `sizeof(cl_device_id) * 1` is allocated to `clkit.devices`.

If `type` is `CL_DEVICE_TYPE_ALL`, `clkit.num_devices` is set with number related with [clGetDeviceIDs](https://www.khronos.org/registry/OpenCL/sdk/1.0/docs/man/xhtml/clGetDeviceIDs.html). For example, if platform has 1 cpu and 1 gpu `clkit.num_devices` is set 2 and memory with `sizeof(cl_device_id) * 2` is allocated to `clkit.devices`.

It returns `CLKIT_FAIL` if there is error from memory allocating or OpenCL API, else `CLKIT_SUCCESS`.

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

**updating**