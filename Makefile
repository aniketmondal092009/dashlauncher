CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -Iinclude
LIBS = -lX11
TARGET = dash

SRCS = src/main.cpp src/args.cpp src/window.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) a.out

install: $(TARGET)
	install -D -m 755 $(TARGET) /usr/local/bin/$(TARGET)

.PHONY: all clean install
