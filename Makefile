CC := cc
CFLAGS := -Wall -Wextra -std=c11 $(shell pkg-config --cflags libconfuse)
LDFLAGS := $(shell pkg-config --libs libconfuse)

BUILD_DIR := build
TARGET := syncme

SRCS := $(shell find src -name '*.c')
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
