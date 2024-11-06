# Define the compiler
CXX = g++

# Define the flags for the compiler
CXXFLAGS = -Ihdr

# Define the build directory variable 
BUILD_DIR = build

# Define the target executable
TARGET = $(BUILD_DIR)/app-monitoring

# Define the source and header files
SRCS = $(wildcard *.cpp)
HDRS = $(wildcard *.h)

# Define the object files
OBJS = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Ensure the build directory exists
$(BUILD_DIR):
	@test -d $(BUILD_DIR) || mkdir -p $(BUILD_DIR)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(CXXFLAGS)

# Compile the source files into object files
build/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)