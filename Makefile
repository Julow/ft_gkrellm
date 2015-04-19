# LOL

NAME := ft_gkrellm
C_DIR := srcs
H_DIRS := h
O_DIR := o
LIBS := 
CC := clang++
FLAGS := -Wall -g
LINKS := -framework sfml-graphics -framework sfml-window -framework sfml-system -F SFML/Frameworks -lncurses
HEADS := -Ih 

all: $(NAME)

o/CatModule.cpp.o: srcs/CatModule.cpp h/CatModule.hpp
	@$(COMPILE)
o/Core.cpp.o: srcs/Core.cpp h/Core.hpp h/IMonitorDisplay.hpp h/IMonitorModule.hpp h/NCursesDisplay.hpp
	@$(COMPILE)
o/CpuModule.cpp.o: srcs/CpuModule.cpp h/CpuModule.hpp
	@$(COMPILE)
o/DiskModule.cpp.o: srcs/DiskModule.cpp h/DiskModule.hpp h/Core.hpp
	@$(COMPILE)
o/HostModule.cpp.o: srcs/HostModule.cpp h/HostModule.hpp
	@$(COMPILE)
o/LoadModule.cpp.o: srcs/LoadModule.cpp h/LoadModule.hpp h/Core.hpp
	@$(COMPILE)
o/main.cpp.o: srcs/main.cpp h/ft_gk.h h/Core.hpp h/NCursesDisplay.hpp h/HostModule.hpp h/CpuModule.hpp h/TimeModule.hpp h/OsInfoModule.hpp h/DiskModule.hpp h/ProcessModule.hpp h/NetworkModule.hpp h/LoadModule.hpp h/CatModule.hpp h/MemModule.hpp h/MemActivityModule.hpp
	@$(COMPILE)
o/MemActivityModule.cpp.o: srcs/MemActivityModule.cpp h/MemActivityModule.hpp h/Core.hpp
	@$(COMPILE)
o/MemModule.cpp.o: srcs/MemModule.cpp h/MemModule.hpp h/Core.hpp
	@$(COMPILE)
o/NCursesDisplay.cpp.o: srcs/NCursesDisplay.cpp h/NCursesDisplay.hpp h/IMonitorModule.hpp h/Core.hpp
	@$(COMPILE)
o/NetworkModule.cpp.o: srcs/NetworkModule.cpp h/NetworkModule.hpp h/Core.hpp
	@$(COMPILE)
o/OsInfoModule.cpp.o: srcs/OsInfoModule.cpp h/OsInfoModule.hpp
	@$(COMPILE)
o/ProcessModule.cpp.o: srcs/ProcessModule.cpp h/ProcessModule.hpp h/Core.hpp
	@$(COMPILE)
o/Stats.cpp.o: srcs/Stats.cpp h/Stats.hpp
	@$(COMPILE)
o/TimeModule.cpp.o: srcs/TimeModule.cpp h/TimeModule.hpp
	@$(COMPILE)

MSG_0 := printf '\033[0;32m%-26.26s\033[0;0m\r'
MSG_1 := printf '\033[0;31m%-26.26s\033[0;0m\n'

COMPILE = $(MSG_0) $< ; $(CC) $(FLAGS) $(HEADS) -c -o $@ $< || $(MSG_1) $<

O_FILES := o/CatModule.cpp.o \
		o/Core.cpp.o \
		o/CpuModule.cpp.o \
		o/DiskModule.cpp.o \
		o/HostModule.cpp.o \
		o/LoadModule.cpp.o \
		o/main.cpp.o \
		o/MemActivityModule.cpp.o \
		o/MemModule.cpp.o \
		o/NCursesDisplay.cpp.o \
		o/NetworkModule.cpp.o \
		o/OsInfoModule.cpp.o \
		o/ProcessModule.cpp.o \
		o/Stats.cpp.o \
		o/TimeModule.cpp.o

$(NAME): SFML o/ $(LIBS) $(O_FILES)
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

SFML:
	@curl -o "SFML.tar.gz" "http://mirror0.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz"
	@mkdir SFML
	@tar -xzf SFML.tar.gz -C SFML --strip-components=1
	@mv SFML/extlibs/freetype.framework SFML/Frameworks/
	@rm -f "SFML.tar.gz"
	@echo "----> \033[0;32mexport DYLD_FRAMEWORK_PATH=\"$(shell pwd)/SFML/Frameworks\""

make:
	@bash './makemake.sh' re

.PHONY: all clean fclean re make
