# Nom de votre bibliothèque
LIBRARY = kuwazy_engine.so

SRC_DIR = src/math
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
CC = gcc
CFLAGS = -Wall -Wextra -Werror -shared -fPIC
LDFLAGS = -lm

all: $(LIBRARY)

$(LIBRARY): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*.o $(LIBRARY)

.PHONY: all clean
