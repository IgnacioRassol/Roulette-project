TARGET_EXEC := simulation

BUILD_DIR := ./build
SRC_DIRS := ./src

SRCS := src/bet_checker.cpp src/main.cpp src/player.cpp src/roulette_result.cpp src/roulette.cpp src/simulation.cpp

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

CXXFLAGS := -Wall -Weffc++ -Werror -Wconversion -Wsign-conversion -pedantic-errors -std=c++14 -O2 -DNDEBUG

# The final build step.
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm -r $(BUILD_DIR)
