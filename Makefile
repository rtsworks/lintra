# Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks)
# SPDX-License-Identifier: MIT

# --------------------------------- GENERAL ---------------------------------- #
# The target executable to be created
TARGET := prog.out
# Build selection variable (debug by default)
BUILD := debug
# Number of threads to be used
THREADS := 1

# ----------------------------- Directory paths ------------------------------ #
# Source file directory
SRC_DIR := ./src
# Include file directory
INCLUDE_DIR := ./include
# Script file directory
SCRIPT_DIR := ./script
# Build directory root
BUILD_ROOT = ./build
# Contains all the Build artifacts
BUILD_DIR := $(BUILD_ROOT)/$(BUILD)
# Contains CPPCheck related artifacts
CPPCHECK_DIR := $(BUILD_ROOT)/cppcheck
# Bin directory root
BIN_ROOT = ./bin
# Contains the output files
BIN_DIR := $(BIN_ROOT)/$(BUILD)

# ---------------------------------- Files ----------------------------------- #
# Find all the source files to be compiled
SRCS := $(shell find $(SRC_DIR) -type f -name '*.c')
# Path to all the .o files
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
# Path to all the .d files
DEPS := $(OBJS:.o=.d)

# ----------------------------- Compiler config ------------------------------ #
# Select the C compiler
CC := gcc
# Release build compiler flags
CFLAGS.release := -Os
# Debug build compiler flags
CFLAGS.debug := -O0 -ggdb3
# Selected (release/debug) compiler flags
CFLAGS := $(CFLAGS.$(BUILD)) -std=c99 -pedantic -Wall -Wextra -Werror        \
							 -Winline -Wconversion -Wpadded -Wshadow -Wundef \
							 -Wdouble-promotion -fno-common -fstack-usage    \
							 -ffunction-sections -fdata-sections -pthread
# Release build preprocessor flags
CPPFLAGS.release := -DNDEBUG
# Debug build preprocessor flags
CPPFLAGS.debug :=
# Selected (release/debug) preprocessor flags
CPPFLAGS := -D_GNU_SOURCE $(CPPFLAGS.$(BUILD)) -I$(SRC_DIR) -I$(INCLUDE_DIR) \
            -MMD -MP
# Release build linker flags
LDFLAGS.release := -s
# Debug build linker flags
LDFLAGS.debug :=
# Library paths
LIBPATHS :=
# Selected (release/debug) linker flags
LDFLAGS := $(LDFLAGS.$(BUILD)) $(LIBPATHS) -Wl,-Map=$(BIN_DIR)/$(TARGET).map \
           -Wl,--gc-sections #-Wl,--print-gc-sections
# Link libraries
LDLIBS := -lm -pthread

# ------------------------------ CPPCheck config ----------------------------- #

# Flags to be used by the CPPCheck tool
CPPCHECK_FLAGS := --verbose
CPPCHECK_FLAGS += --error-exitcode=1
CPPCHECK_FLAGS += --suppress=missingIncludeSystem
CPPCHECK_FLAGS += --suppress=unmatchedSuppression
CPPCHECK_FLAGS += --suppress=misra-c2012-21.6
CPPCHECK_FLAGS += --inline-suppr
CPPCHECK_FLAGS += -I$(INCLUDE_DIR)
CPPCHECK_FLAGS += --cppcheck-build-dir=$(CPPCHECK_DIR)
CPPCHECK_FLAGS += --relative-paths=.
CPPCHECK_FLAGS += --platform=$(SCRIPT_DIR)/type_sizes.xml
CPPCHECK_FLAGS += --language=c
CPPCHECK_FLAGS += --std=c99
CPPCHECK_FLAGS += --library=posix.cfg
CPPCHECK_FLAGS += --enable=all
CPPCHECK_FLAGS += --safety
CPPCHECK_FLAGS += --check-level=exhaustive
CPPCHECK_FLAGS += --report-type=misra-c-2012
CPPCHECK_FLAGS += --inconclusive
CPPCHECK_FLAGS += --addon=$(SCRIPT_DIR)/misra.json
CPPCHECK_FLAGS += --addon=$(SCRIPT_DIR)/threadsafety.json
CPPCHECK_FLAGS += -j$(THREADS)

# -------------------------------- Make rules -------------------------------- #

# These targets are not real files, always run the recipe
.PHONY: all lint test build clean

# Make rule order, if any rule fails the process stops
# Default make: Run the build rule
all: build
# Build rule runs the test rule
build: test
# Test rule runs lint rule
test: lint

# Rule for linting the project (Require ./build/cppcheck dir to exist first)
lint: | $(CPPCHECK_DIR)
	cppcheck $(CPPCHECK_FLAGS) $(SRC_DIR)

# Rule for running ceedling tests + coverage
test:
	ceedling clobber gcov:all

# Rule for building the target
build: $(BIN_DIR)/$(TARGET)

# Link the object files into an executable (Require ./bin dir to exist first)
$(BIN_DIR)/$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

# Compile all the sources into object files (Require ./build dir to exist first)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Work directory creation rules
$(BIN_DIR) $(BUILD_DIR) $(CPPCHECK_DIR):
	mkdir -p $@

# Delete the ./build and ./bin directories
clean:
	rm -rf $(BUILD_ROOT)
	rm -rf $(BIN_ROOT)

# Include .d files to ensure make detects changes in .h files
-include $(DEPS)
