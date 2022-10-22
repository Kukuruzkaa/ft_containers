NEW_DIR				= mkdir -p
DEL_DIR				= rm -rf

CC					= c++
COMPILE_FLAG		= $(DEPS_FLAG) -std=c++98 -Wall -Werror -Wextra -g
FT_FLAG				= 
STD_FLAG			= -DNAMESPACE=std
DEPS_FLAG			= -MMD -MP
INCLUDES_FLAG		= -I ./

OBJS_DIR_FT			= ft_objs/
OBJS_DIR_STD		= std_objs/

DEFAULT_FILES		= operator structor member accessor

VPATH				= tests/
SRCS				= $(addsuffix .cpp,		main\
											stack_tests\
											vector_tests\
											map_tests)
OBJS_FT				= $(patsubst %.cpp, $(OBJS_DIR_FT)%.o, $(SRCS))
OBJS_STD			= $(patsubst %.cpp, $(OBJS_DIR_STD)%.o, $(SRCS))
DEPS				= $(OBJS_FT:.o=.d) $(OBJS_STD:.o=.d)

FT_EXE				= ft_containers
STD_EXE				= std_containers

all					: $(OBJS_DIR_FT) $(OBJS_DIR_STD) $(FT_EXE) $(STD_EXE)

$(OBJS_DIR_FT)			:
					$(NEW_DIR) $@

$(OBJS_DIR_STD)			:
					$(NEW_DIR) $@

$(FT_EXE)			: $(OBJS_FT)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(STD_EXE)			: $(OBJS_STD)
					$(CC) $(COMPILE_FLAG) $^ -o $@

$(OBJS_DIR_FT)%.o	: %.cpp
					$(CC) $(COMPILE_FLAG) $(FT_FLAG) -c $< $(INCLUDES_FLAG) -o $@

$(OBJS_DIR_STD)%.o	: %.cpp
					$(CC) $(COMPILE_FLAG) $(STD_FLAG) -c $< $(INCLUDES_FLAG) -o $@

clean				:
					$(DEL_DIR) $(OBJS_DIR_FT) $(OBJS_DIR_STD)

fclean				: clean
					$(DEL_DIR) $(FT_EXE) $(STD_EXE)

re					:
					make fclean
					make all

-include			$(DEPS)

.PHONY				: all clean fclean re
