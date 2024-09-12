# Compiler and flags
CXX      = g++
CXXFLAGS = -std=c++11 

# Executable
TARGET   = main

# Object files
OBJS     = main.o studentDetailsImp.o studentTypeImp.o calculatorImp.o fileHandlerImp.o

# Header file dependencies
DEPS     = studentDetails.h studentType.h calculator.h fileHandler.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile main.cpp
main.o: main.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile studentDetailsImp.cpp
studentDetailsImp.o: studentDetailsImp.cpp studentDetails.h
	$(CXX) $(CXXFLAGS) -c studentDetailsImp.cpp

# Compile studentTypeImp.cpp
studentTypeImp.o: studentTypeImp.cpp studentType.h
	$(CXX) $(CXXFLAGS) -c studentTypeImp.cpp

# Compile calculatorImp.cpp
calculatorImp.o: calculatorImp.cpp calculator.h
	$(CXX) $(CXXFLAGS) -c calculatorImp.cpp

# Compile fileHandlerImp.cpp
fileHandlerImp.o: fileHandlerImp.cpp fileHandler.h
	$(CXX) $(CXXFLAGS) -c fileHandlerImp.cpp

# Clean target: removes object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets to avoid conflicts with file names
.PHONY: clean all
