# Define the compiler 
CXX = g++ 

# Define the flags for the compiler 
CXXFLAGS = `` 

# Define the target executable 
TARGET = app-monitoring

# Define the source files 
SRCS = main.cpp 

# Define the build directory
BUILD_DIR = ./build

# Create the build directory if it doesn't exist 
$(BUILD_DIR): 
	@test -d $(BUILD_DIR) || mkdir -p $(BUILD_DIR)

# Define the object files 
OBJS = $(BUILD_DIR)/$(SRCS:.cpp=.o) 

# Default target 
all: $(BUILD_DIR) $(TARGET) 

# Link the object files to create the executable 
$(TARGET): $(OBJS) 
	$(CXX) -o $(BUILD_DIR)/$(TARGET) $(OBJS) $(CXXFLAGS) 

# Compile the source files into object files 
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) 
	
# Clean the build directory 
clean: 
	rm -f $(OBJS) $(BUILD_DIR)/$(TARGET)