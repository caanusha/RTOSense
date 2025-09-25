CXX = g++
CXXFLAGS = -Wall -O2 -std=c++17 -Iinclude
LDFLAGS = -lrt -lcurl

SRC = main.cpp \
      src/ClientAgent.cpp

OBJ = $(SRC:.cpp=.o)

TARGET = rtosense

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
