# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
    printf "$(KGRN)[clkit]$(KNRM) compile $(1)\n"
    $(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
    $(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libclkit.a

# path
SRCDIR = srcs

OBJDIR = objs

INCDIR = includes

LIBFT_PATH = ../libft

# compiler options
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I ./$(INCDIR)\
	-I $(LIBFT_PATH)/includes\

# srcs
SRC_CMD_QUEUE = enqueue_ndrange_kernel.c\
	enqueue_read_buffer.c\
	enqueue_write_buffer.c\
	flush.c\
	finish.c\

SRC_HANDLE_ERROR = platform_err.c\
	device_err.c\
	context_err.c\
	cmd_queue_err.c\
	cmd_queue_err2.c\
	memory_err.c\
	program_err.c\
	kernel_err.c\
	release_err.c\
	handle_error_utils.c\

SRC_KERNEL = create_kernel.c\
	set_kernel_arg.c\
	create_program.c\
	build_program.c\
	get_program_build_info.c\

SRC_MEMORY = create_buffer.c\

SRC_PREREQUISITES = set_device.c\
	create_context.c\
	create_cmd_queue.c\

SRC_UTILS = get_device_info.c\
	concat_kernel_src.c\

SRC_RELEASE = release_all.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_CMD_QUEUE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_HANDLE_ERROR:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_KERNEL:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_MEMORY:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PREREQUISITES:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_RELEASE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_UTILS:.c=.o))

# compile objs
HEADERS = $(INCDIR)/clkit.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(LIBFT_PATH)/includes/get_next_line.h\

$(OBJDIR)/%.o : $(SRCDIR)/cmd_queue/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/handle_error/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/kernel/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/memory/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/prerequisites/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/release/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)
$(OBJDIR)/%.o : $(SRCDIR)/utils/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

pre_build :
	@printf "$(KGRN)[clkit] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[clkit] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all pre_build post_build clean fclean re