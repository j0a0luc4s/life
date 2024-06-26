TARGET := life

BUILD_DIR := ./build
SRC_DIRS := ./src

CXX := g++

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

LDFLAGS := -lGL -lm -lpthread -ldl -lrt -lX11
LDFLAGS := $(LDFLAGS) -L./raylib/build/raylib
LDFLAGS := $(LDFLAGS) -lraylib

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
INC_FLAGS := $(INC_FLAGS) -I./raylib/build/raylib/include

CPPFLAGS := $(INC_FLAGS) -MMD -MP
CXXFLAGS := -O3

$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

run: $(BUILD_DIR)/$(TARGET)
	$(BUILD_DIR)/$(TARGET)

.PHONY: clean

clean: 
	rm -r $(BUILD_DIR)

-include $(DEPS)
