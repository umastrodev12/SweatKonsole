TARGET = sweatkonsole.exe
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LDFLAGS = -lgdi32 -mwindows

SRC_DIR = src
OBJ_DIR = obj

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) 2>nul || mkdir $(OBJ_DIR) 2>nul || true
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@del /q $(OBJ_DIR)\*.o $(TARGET) 2>nul || rm -rf $(OBJ_DIR) $(TARGET) 2>nul || true

.PHONY: all clean
