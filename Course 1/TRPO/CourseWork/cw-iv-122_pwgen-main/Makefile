APP_NAME = pwgen
LIB_NAME = libpwgen
TEST_NAME = test
DEBUG =

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -I testparty -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = c

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_NAME) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_NAME)/%.c=$(OBJ_DIR)/$(TEST_NAME)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: $(APP_NAME)
$(APP_NAME): $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -o $@ $^

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -c -o $@ $<

.PHONY: $(TEST_NAME)
$(TEST_NAME): $(TEST_PATH)

-include $(DEPS)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH) 
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	rm -rf $(DEPS) $(APP_OBJECTS) $(LIB_OBJECTS) $(TEST_OBJECTS)

run:
	-$(APP_PATH)

run_test:
	-$(TEST_PATH)