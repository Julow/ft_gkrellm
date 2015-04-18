#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makemake.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/07 22:29:29 by jaguillo          #+#    #+#              #
#    Updated: 2015/04/12 00:41:47 by jaguillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#
# makemake.sh
#
# Makefile generator
# For all language that compile into .o
#
# Usage:
#  ./makemake [re]
#
# re: If a Makefile exists, use the same config otherwise, use default values.
#

MAKEFILE="Makefile"
MAKEMAKE="$0"
MAKEMODE="$1"

function prompt()
{
	DEF=""
	if [[ -f "$MAKEFILE" ]]; then
		if [[ ! -z "$3" ]]; then
			DEF="`cat $MAKEFILE | grep "$3 := " | cut -d ' ' -f 3-`"
		fi
		if [[ -z "$DEF" ]]; then
			DEF="$2"
		fi
	else
		DEF="$2"
	fi
	if [[ "$MAKEMODE" == "re" ]]; then
		echo "$DEF"
		return
	fi
	if [[ ! -z "$DEF" ]]; then
		MSG="$1 ($DEF)"
	else
		MSG="$1"
	fi
	read -p "> $MSG: " R
	if [[ -z "$R" ]]; then
		R="$DEF"
	fi
	echo "$R"
};

NAME=`prompt "NAME" "$DEF_NAME" "NAME"`

C_DIR=`prompt "Sources directory" "." "C_DIR"`
H_DIRS=`prompt "Headers directory" "." "H_DIRS"`
O_DIR=`prompt "Objects directory" "o" "O_DIR"`

LIBS=`prompt "Libraries" "" "LIBS"`

CC=`prompt "Compiler" "clang++" "CC"`
FLAGS=`prompt "Flags" "-Wall -Wextra -Werror -O2" "FLAGS"`

DEF=""
for L in $LIBS; do
	DEF="-L$L $DEF"
done
LINKS=`prompt "Libraries links" "$DEF" "LINKS"`

DEF=""
for H in $H_DIRS; do
	DEF="-I$H $DEF"
done
for L in $LIBS; do
	DEF="-I$L $DEF"
done
HEADS=`prompt "Headers links" "$DEF" "HEADS"`

function includes()
{
	INCLUDES="`cat $1 | grep "#include "'"' | sed -E 's/#include "([^"]+)"/\1/' | tr '\n' ' '`"
	for H in $INCLUDES; do
		for INC in $H_DIRS; do
			if [[ -f "$INC/$H" ]]; then
				includes "$INC/$H"
				printf " $INC/$H"
			fi
		done
	done
};

C_FILES=`find "$C_DIR" -type f -print | grep -E '\.[sSc](pp)?$'`
O_FILES=""
O_DIRS=""

MAX_LEN="${#NAME}"

PHONY=""

function create_c_rule()
{
	if [[ "${#1}" -gt "$MAX_LEN" ]]; then
		MAX_LEN="${#1}"
	fi
	O_FILE=`echo "$1.o" | sed -E 's#^'"$C_DIR"'#'"$O_DIR"'#'`
	if [[ -z "$O_FILES" ]]; then
		O_FILES="$O_FILE"
	else
		O_FILES="$O_FILES \\
		$O_FILE"
	fi
	printf "$O_FILE: $1"
	O_DIRS="$O_DIRS `echo "$O_FILE" | sed -E 's#[^/]+$##' | tr -d '\n'`"
	includes "$1"
	echo
	echo "	@\$(COMPILE)"
};

function create_makefile()
{
	echo "# LOL

NAME := $NAME
C_DIR := $C_DIR
H_DIRS := $H_DIRS
O_DIR := $O_DIR
LIBS := $LIBS
CC := $CC
FLAGS := $FLAGS
LINKS := $LINKS
HEADS := $HEADS

all: \$(NAME)
"

	for F in $C_FILES; do
		create_c_rule "$F"
	done

	for M in $LIBS; do
		PHONY="$PHONY $M"
		echo "$M:"
		echo "	@make -C $M"
		echo
	done

	echo "
MSG_0 := printf '\\033[0;32m%-${MAX_LEN}.${MAX_LEN}s\\033[0;0m\\r'
MSG_1 := printf '\\033[0;31m%-${MAX_LEN}.${MAX_LEN}s\\033[0;0m\\n'

COMPILE = \$(MSG_0) \$< ; \$(CC) \$(FLAGS) \$(HEADS) -c -o \$@ \$< || \$(MSG_1) \$<

O_FILES := $O_FILES

\$(NAME):`echo "$O_DIRS" | tr ' ' '\n' | sort -u | tr '\n' ' '`\$(LIBS) \$(O_FILES)
	@\$(MSG_0) \$@ ; \$(CC) \$(FLAGS) -o \$@ \$(O_FILES) \$(LINKS) && echo || \$(MSG_1) \$@

$O_DIR/:
	@mkdir -p \$@ 2> /dev/null || true

$O_DIR/%:
	@mkdir -p \$@ 2> /dev/null || true

clean:
	@rm -f \$(O_FILES) 2> /dev/null || true
	@rmdir -p $O_DIR 2> /dev/null || true

fclean: clean
	@rm -f $NAME 2> /dev/null || true

re: fclean all

make:
	@bash '$MAKEMAKE' re

.PHONY: all clean fclean re make$PHONY"
};

create_makefile > $MAKEFILE && printf "\033[0;32mMakefile ready." || printf "\033[0;31mCannot create Makefile"

printf "\033[0;0m\n"
