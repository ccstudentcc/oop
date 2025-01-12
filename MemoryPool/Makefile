CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O3 -I.
TARGET = test
SRCS = test.cpp

all: $(TARGET) run

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean run
