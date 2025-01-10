CC = gcc
CFLAGS = -Wall -g
LIBS = -lasound -lm

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

INCLUDE = -I$(INCLUDE_DIR)

.PHONY: all clean run

all: $(BIN_DIR) $(BUILD_DIR) $(BIN_DIR)/bleep

$(BIN_DIR) $(BUILD_DIR):
	@mkdir -p $@

$(BIN_DIR)/bleep: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

run: all
	@./$(BIN_DIR)/bleep -f 440 -d 1000 -a 0.5