SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
ADDITIONAL_FILES = $(wildcard $(SRC_DIR)/physics_engine/physicsEngine.cpp)
OBJ_NAME = physics
INCLUDE_PATHS = -Iinclude
LIBRARY_PATHS = -Llib/SDL2 -Llib/SDL2_image
COMPILER_FLAGS = -std=c++11 -Wall -O0 -g
LINKER_FLAGS = -lSDL2

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(ADDITIONAL_FILES) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)
