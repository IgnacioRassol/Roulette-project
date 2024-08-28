TARGET_EXEC := simulation

BUILD_DIR := ./build
SRC_DIRS := ./src

TEST_DIR := ./src/test
TEST_BUILD_DIR := ./test_build
CATCH2 := ./src/test/catch2/catch_amalgamated.cpp

SRCS := src/bet_checker.cpp src/main.cpp src/player.cpp src/roulette_result.cpp src/roulette.cpp src/simulation.cpp

TEST_SRCS := ./src/test/catch2/catch_amalgamated.cpp src/test/roulette_result_test.cpp src/roulette_result.cpp src/bet_checker.cpp src/test/bet_checker_test.cpp

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
OBJS_TEST := $(TEST_SRCS:%=$(TEST_BUILD_DIR)/%.o)

CXXFLAGS := -Wall -Weffc++ -Werror -Wconversion -Wsign-conversion -pedantic-errors -std=c++14 -O2 -DNDEBUG
CXXTESTFLAGS := -std=c++14 -O2 -DNDEBUG -I ./src -I ./src/test/catch2

.PHONY: all
$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


test: $(OBJS_TEST)
	$(CXX) $(OBJS_TEST) -o $@

$(TEST_BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXTESTFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

.PHONY: clean_test
clean_test:
	rm -r $(TEST_BUILD_DIR)
