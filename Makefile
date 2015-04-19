# LOL

NAME := ft_gkrellm
C_DIR := srcs
H_DIRS := h
O_DIR := o
LIBS := 
CC := clang++
FLAGS := -Wall -g
LINKS := -lncurses
HEADS := -Ih 

all: $(NAME)

o/CatModule.cpp.o: srcs/CatModule.cpp h/CatModule.hpp
	@$(COMPILE)
o/Core.cpp.o: srcs/Core.cpp h/Core.hpp h/IMonitorDisplay.hpp h/IMonitorModule.hpp h/NCursesDisplay.hpp
	@$(COMPILE)
o/CpuModule.cpp.o: srcs/CpuModule.cpp h/CpuModule.hpp
	@$(COMPILE)
o/HostModule.cpp.o: srcs/HostModule.cpp h/HostModule.hpp
	@$(COMPILE)
o/main.cpp.o: srcs/main.cpp h/ft_gk.h h/Core.hpp h/NCursesDisplay.hpp h/HostModule.hpp h/CpuModule.hpp h/TimeModule.hpp h/OsInfoModule.hpp
	@$(COMPILE)
o/NCursesDisplay.cpp.o: srcs/NCursesDisplay.cpp h/NCursesDisplay.hpp h/IMonitorModule.hpp h/Core.hpp
	@$(COMPILE)
o/OsInfoModule.cpp.o: srcs/OsInfoModule.cpp h/OsInfoModule.hpp
	@$(COMPILE)
o/Stats.cpp.o: srcs/Stats.cpp h/Stats.hpp
	@$(COMPILE)
o/TimeModule.cpp.o: srcs/TimeModule.cpp h/TimeModule.hpp
	@$(COMPILE)

MSG_0 := printf '\033[0;32m%-23.23s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-23.23s\033[0;0m\n'

COMPILE = $(MSG_0) $< ; $(CC) $(FLAGS) $(HEADS) -c -o $@ $< || $(MSG_1) $<

O_FILES := o/CatModule.cpp.o \
		o/Core.cpp.o \
		o/CpuModule.cpp.o \
		o/HostModule.cpp.o \
		o/main.cpp.o \
		o/NCursesDisplay.cpp.o \
		o/OsInfoModule.cpp.o \
		o/Stats.cpp.o \
		o/TimeModule.cpp.o

$(NAME): o/ $(LIBS) $(O_FILES)
	@$(MSG_0) $@ ; $(CC) $(FLAGS) -o $@ $(O_FILES) $(LINKS) && echo || $(MSG_1) $@

o/:
	@mkdir -p $@ 2> /dev/null || true

o/%:
	@mkdir -p $@ 2> /dev/null || true

clean:
	@rm -f $(O_FILES) 2> /dev/null || true
	@rmdir -p o 2> /dev/null || true

fclean: clean
	@rm -f ft_gkrellm 2> /dev/null || true

re: fclean all

make:
	@bash './makemake.sh' re

.PHONY: all clean fclean re make
