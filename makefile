TARGET_EXEC := simulation

BUILD_DIR := ./build
SRC_DIRS := ./src

TEST_DIR := ./src/test
TEST_OUT := ./test
CATCH2 := ./src/test/catch2/catch_amalgamated.cpp

SRCS := src/bet_checker.cpp src/main.cpp src/player.cpp src/roulette_result.cpp src/roulette.cpp src/simulation.cpp

TEST_SRCS := src/test/roulette_result_test.cpp src/roulette_result.cpp

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CXXFLAGS := -Wall -Weffc++ -Werror -Wconversion -Wsign-conversion -pedantic-errors -std=c++14 -O2 -DNDEBUG
CXXTESTFLAGS := -std=c++14 -O2 -DNDEBUG -I ./src -I ./src/test/catch2

.PHONY: all
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Build step for C++ test

test: $(TEST_SRCS) 
	mkdir -p $(TEST_OUT)
	$(CXX) $(CXXTESTFLAGS) $(TEST_SRCS) $(CATCH2) -o $(TEST_OUT)/test

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

.PHONY: clean_test
clean_test:
	rm -r $(TEST_OUT)
