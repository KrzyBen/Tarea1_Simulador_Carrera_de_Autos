CXX = g++

CXXFLAGS = -std=c++11 -pthread

TARGET = carreraMake

SRCS = carreraMake.cpp

all: $(TARGET)

$(TARGET):	$(SRCS)
	$(CXX)	$(CXXFLAGS)	-o	$(TARGET)	$(SRCS)

clean:
	rm -f $(TARGET)
