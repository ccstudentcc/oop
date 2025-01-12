CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2 -I.
TARGET = test
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET) run

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean run