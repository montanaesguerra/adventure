CC := g++
CFLAGS := -g -std=c++17
SRC := main.cpp
OBJ := main.o
TARGET := main

# list your .h files here
HEADERS = Location.h

# list .cpp files here according to main program, tests, or both
PROGRAM_FILES = main.cpp
TEST_FILES = tests.cpp
SHARED_FILES = Location.cpp

# ==== Default Target ====
all: $(TARGET)

# ==== Build Target ====
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# ==== Object File Rule ====
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# ==== Clean ====
.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET)