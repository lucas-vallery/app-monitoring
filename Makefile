# Compiler
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Application name 
APP_NAME = main

# Directories
SRCDIRS = ./HeartbeatReceiver/src ./
BUILDDIR = ./build
OBJDIR = $(BUILDDIR)

# Source files
SRC = $(wildcard $(addsuffix /*.cpp,$(SRCDIRS)))
OBJ = $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

# Final executable
TARGET = $(BUILDDIR)/$(APP_NAME)

# Rule to create build directories and subdirectories 
$(OBJDIR): 
	mkdir -p $(OBJDIR) $(BUILDDIR) 
	for dir in $(SRCDIRS); do \
		mkdir -p $(OBJDIR)/$$dir;\
	done

# Rule to create object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link object files and create the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Clean up the build directory
clean:
	rm -rf $(BUILDDIR)

# Default target
all: $(TARGET)