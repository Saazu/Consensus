#Author: Alfred Delle
#Date: 27th October 2018
#-------------------------------------------------
#Macro defintions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = main.o tools.o agent.o simulator.o
TARGET = consensus
#-------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)

clean:
	rm -f $(OBJ) $(TARGET)
#-------------------------------------------------
#Dependencies
main.o: main.cpp tools.cpp agent.hpp simulator.hpp
tools.o: tools.cpp tools.hpp
agent.o: agent.cpp agent.hpp
simulator.o: simulator.cpp simulator.hpp