FAULTY_MAKE_CONFIG ?= config.mk
include ${FAULTY_MAKE_CONFIG}

# ASSUMPTIONS:
#   1. You are building on 64-bit Ubuntu.
#   2. You are building only for 64-bit Linux and 64-bit Windows.
#   3. You have proper build systems for both Linux and Windows.

# ===== Configuration =====

FILE_NAME=faulty

# Be careful with what you set BUILD_DIR to -- it gets rm -rf'd by `make clean`.
BUILD_DIR=./build


VALGRIND_DIR=./valgrind

LINUX_BUILD_DIR=${BUILD_DIR}/linux-x86_64
WINDOWS_BUILD_DIR=${BUILD_DIR}/windows-x86_64

LINUX_EXE=${LINUX_BUILD_DIR}/${FILE_NAME}
WINDOWS_EXE=${WINDOWS_BUILD_DIR}/${FILE_NAME}.exe

SRCFILES != find 'src' -name '*.c'

# ===== Flags =====

LINUX_SDL2_CFLAGS  != ${SDL2_CONFIG} --cflags
LINUX_SDL2_LDFLAGS != ${SDL2_CONFIG} --static-libs

WINDOWS_SDL2_CFLAGS != ${WINDOWS_SDL2_CONFIG} --cflags
WINDOWS_SDL2_LDFLAGS != ${WINDOWS_SDL2_CONFIG} --static-libs

# TODO: Figure out if these are correct. I copypasta'd them from https://github.com/duckinator/dux/blob/main/Makefile
#       and removed things that were clearly specific to operating systems.
COMPILER_FLAGS := -std=c11 -Wall -g -Iinclude -Wextra -Wunused -Wformat=2 -Winit-self -Wmissing-include-dirs -Wstrict-overflow=4 -Wfloat-equal -Wwrite-strings -Wconversion -Wundef -Wtrigraphs -Wunused-parameter -Wunknown-pragmas -Wcast-align -Wswitch-enum -Waggregate-return -Wmissing-noreturn -Wmissing-format-attribute -Wpacked -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wdisabled-optimization -Wbad-function-cast -Wunused-function -Werror=implicit-function-declaration -gdwarf-2 -pedantic-errors -O0 -Wno-gnu-zero-variadic-macro-arguments

LINKER_FLAGS := ${SDL2_LDFLAGS}

LINUX_COMPILER_FLAGS := ${COMPILER_FLAGS} ${LINUX_SDL2_CFLAGS}
LINUX_LINKER_FLAGS   := ${LINKER_FLAGS} ${LINUX_SDL2_LDFLAGS}

WINDOWS_COMPILER_FLAGS := ${COMPILER_FLAGS} ${WINDOWS_SDL2_CFLAGS}
WINDOWS_LINKER_FLAGS   := ${LINKER_FLAGS} ${WINDOWS_SDL2_LDFLAGS}

# ===== Targets =====

release: all test
	./bin/release.sh

all: prereqs linux windows

prereqs: ${FAULTY_MAKE_CONFIG}
	@mkdir -p ${LINUX_BUILD_DIR}
	@mkdir -p ${WINDOWS_BUILD_DIR}

linux: prereqs ${LINUX_EXE}

${LINUX_EXE}:
	${CC} ${COMPILER_FLAGS} ${LINKER_FLAGS} ${SRCFILES} -o ${LINUX_EXE} ${LINUX_SDL2_CFLAGS} ${LINUX_SDL2_LDFLAGS}

windows: prereqs ${WINDOWS_EXE}

${WINDOWS_EXE}:
	${WINDOWS_CC} ${COMPILER_FLAGS} ${LINKER_FLAGS} ${SRCFILES} -o ${WINDOWS_EXE} ${WINDOWS_SDL2_CFLAGS} ${WINDOWS_SDL2_LDFLAGS} --static

config.mk:
	@printf "Before compiling, copy config.mk.dist to config.mk and edit it if necessary.\n"
	@false

valgrind: all
	valgrind --log-file=${VALGRIND_DIR}/valgrind.log --leak-check=full --show-leak-kinds=all --suppressions=./${VALGRIND_DIR}/faulty.supp ${LINUX_EXE}

test:
	@echo "lol just kidding"

clean:
	@find ./src -name '*.o' -delete
	@find ./src -name '*.d' -delete
	@rm -rf ${BUILD_DIR}
	@rm -rf release

.PHONY: all linux windows clean test todo valgrind
