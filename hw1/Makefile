CXX = g++
CXXFLAGS = -std=c++11
SRC = hw1.cpp node.cpp circuit.cpp
TARGET = hw1.o

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)