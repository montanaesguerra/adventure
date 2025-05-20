CC := g++
CFLAGS := -g -std=c++17
SRC := main.cpp
OBJ := main.o
TARGET := main

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