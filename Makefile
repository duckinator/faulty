# What is this?
# =============
#
# tl;dr: the actual Makefile is Makefile.docker.
#
# I (@duckinator) set it up so this Makefile, for each target,
# passes it through to ./build.sh. So, e.g., `make clean all`
# will run:
# 1. ./build.sh clean
# 2. ./build.sh all
#
#
# ./build.sh will:
# 1. Create the Docker image (based on the Dockerfile) if it does not exist.
#   * This includes all dependencies necessary to create builds for all supported platforms.
# 2. Run `make`, passing everything through unmodified.

%:
	# "$@" is actually the rule name, here, not all arguments.
	# Because why borrow a common syntax if you don't change its meaning?
	@./build.sh $@
