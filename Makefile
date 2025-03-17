# Compiler
CC = g++

# Binary file
OBJ = wordle

# Source files
SRC_DIR = src/
SRC_FILES:= $(wildcard $(SRC_DIR)*.cpp)

# Headers directory
HEADER_DIR = include/
HEADER_FILES = $(wildcard $(HEADER_DIR)*.h)
# HEADER_FILES = $(HEADER_DIR)texture.h

# Source objects
OBJ_DIR := bin/
OBJECT_FILES:= $(addprefix $(OBJ_DIR),$(notdir $(SRC_FILES:.cpp=.o)))
# OBJECT_FILES:= $(addprefix $(OBJ_DIR), main.o texture.o)

# Flags
CFLAGS := -Wall -std=c++11 -Wpedantic

# Link objects to exec
$(OBJ): $(OBJECT_FILES)
	@echo "\nLinking..."
	$(CC) $(CFLAGS) -o $(OBJ) $(OBJECT_FILES)
	@echo "Linking for target $(OBJ) succeeded!\n"

# Compile objects
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADER_FILES)
	@echo "\nCompiling $@..."
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ_DIR)*.o *~ $(OBJ) $(HEADER_DIR)/*~