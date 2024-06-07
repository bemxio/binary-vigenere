CC = gcc
CFLAGS = -Wall

SRC_DIR = src
BUILD_DIR = build

tests: $(SRC_DIR)/tests/main.c $(SRC_DIR)/tests/Unity/src/unity.c $(SRC_DIR)/bingenere/bingenere.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $(BUILD_DIR)/tests && $(BUILD_DIR)/tests

examples: $(patsubst $(SRC_DIR)/examples/%.c,$(BUILD_DIR)/%,$(wildcard $(SRC_DIR)/examples/*.c)) | $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR)/%: $(SRC_DIR)/examples/%.c $(SRC_DIR)/bingenere/bingenere.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)