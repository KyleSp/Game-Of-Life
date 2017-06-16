#Kyle Spurlock

#executable name
EXECUTABLE	= gameoflife

#compiler to use
CXX			= g++

#default flags
CXXFLAGS	= -std=c++14 -Wconversion -Wall -Werror -Wextra -pedantic

#list of test sources
TESTSOURCES = $(wildcard test*.cpp)

#list of sources used
SOURCES		= $(wildcard *.cpp)
SOURCES		:= $(filter-out $(TESTSOURCES), $(SOURCES))

#list of objects used
OBJECTS		= $(SOURCES:%.cpp=%.o)

#make release (without debug flags)
release: CXXFLAGS += -O3 -DNDEBUG
release: all

#make all
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
ifeq ($(EXECUTABLE), executable)
	$(CXX) $(CXXFLAGS) $(OBJECTS)
else
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE)
endif

#rule for making object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $*.cpp

#make clean (remove .o files and executables)
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
