

CC = g++
CFLAGS = -Iinclude
SRC = main.cpp

# OBJ = $(SRC:.cpp=.o)   
# optional if you want object files

TARGET = dash

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(OBJ)



