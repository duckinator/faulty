include config.mk

# BULLSHIT EVERYTHING
# BULLSHIT ALL THE THINGS
# FUCK YEAH
# I HAVE NO IDEA WHAT I'M DOING

# THIS MAKEFILE ONLY WORKS ON LINUX RIGHT NOW.

# TODO: I'm making a lot of assumptions about Windows cross-compiling
#       because I have no idea what I'm doing. Probably worth checking them.
LINUX_NAME=faulty
WINDOWS_NAME=faulty.exe

SOURCE_SUFFIXES := '(' -name '*.c' -o -name '*.asm' ')'
SRCFILES := $(shell find 'src' ${SOURCE_SUFFIXES})
OBJFILES := $(patsubst %.asm, %.o, $(patsubst %.c, %.o, $(SRCFILES)))

# TODO: Figure out if these are correct. I copypasta'd them from https://github.com/duckinator/dux/blob/main/Makefile
#       and removed things that were clearly specific to operating systems.
override CFLAGS += -std=c99 -Wall -g -Iinclude -Wextra -Wunused -Wformat=2 -Winit-self -Wmissing-include-dirs -Wstrict-overflow=4 -Wfloat-equal -Wwrite-strings -Wconversion -Wundef -Wtrigraphs -Wunused-parameter -Wunknown-pragmas -Wcast-align -Wswitch-enum -Waggregate-return -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wdisabled-optimization -Wbad-function-cast -Wunused-function -Werror=implicit-function-declaration -gdwarf-2 -pedantic-errors


all: linux windows

linux: config.mk ${LINUX_NAME}

${LINUX_NAME}:
	# ???

windows: config.mk ${WINDOWS_NAME}

${WINDOWS_NAME}:
	# ???


config.mk:
	@printf "Before compiling, copy config.mk.dist to config.mk and edit it if necessary.\n"
	@false

test:
	@echo "lol just kidding"

clean:
	@find ./src -name '*.o'   -delete
	@find ./src -name '*.lib' -delete
	@find ./src -name '*.exe' -delete
	@find ./src -name '*.d'   -delete

.PHONY: all linux windows clean test todo
