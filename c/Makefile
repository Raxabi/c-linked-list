VERSION = 0.0.1

CC = /bin/clang

SRC_DIR = ./src
OBJ_DIR = ./out
BUILD_DIR = ./build

INCL_FLAGS = -I$(SRC_DIR)

SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/**/*.c)
OBJECTS = $(subst ./src,./out,$(SOURCES:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(INCL_FLAGS) -c $< -o $@

objects: $(OBJECTS)

EXCLUDING_TEST = $(filter-out $(wildcard $(OBJ_DIR)/tests/*.o),$(OBJECTS))
test: $(OBJECTS)
	$(CC) $(EXCLUDING_TEST) $(INCL_FLAGS) $(SRC_DIR)/tests/$(test_file) -o $(BUILD_DIR)/test.out

run: test
	./build/test.out

clean:
	echo "Cleaning out dir"
	rm -r ./out/*
	echo "Cleaning build dir"
	rm -r ./build/*

tests:
	echo $(EXCLUDING_TEST)
