BIN_NAME := alpheida

CC := /bin/gcc

BIN_DIR := ./bin
OBJ_DIR := ./obj
SRC_DIR := ./src
INC_DIR := ./include

SRCS := $(shell find $(SRC_DIR) -name '*.c')
OBJS := $(SRCS:%=$(OBJ_DIR)/%.o)

CFLAGS := -I$(INC_DIR) -Wall -Wconversion -Werror
LDFLAGS := -lSDL2

$(BIN_DIR)/$(BIN_NAME): $(OBJS)
	@echo "Linking $(BIN_NAME)..."
	@mkdir -p $(dir $@)
	@$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.c.o: %.c
	@echo "Compiling $<..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -r $(OBJ_DIR)
	@rm -r $(BIN_DIR)

