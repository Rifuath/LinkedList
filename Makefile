# Compiler
CC := g++
DEBUGLEVEL := -O
# Compiler flags
CFLAGS := $(DEBUGLEVEL) -std=c++11 -Wall -Wextra -pedantic
# Include directories
INCLUDES := -I ./include
LDFLAGS :=
 # Source directory
SRC_DIR := src
# Output directory
BUILD_DIR := build
# Executable name
EXEC := LinkedList

# List of source files
SRCS := $(shell find $(SRC_DIR) -name *.cpp)
# List of object files
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Main target
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
# Clean rule
clean:
	rm -rf $(BUILD_DIR) $(EXEC)
