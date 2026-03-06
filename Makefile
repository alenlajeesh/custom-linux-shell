CC=gcc
CFLAGS=-Wall -Wextra -g

SRC=$(wildcard src/*.c)
OBJ=$(SRC:.c=.o)

TARGET=cshell

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	rm -f src/*.o $(TARGET)

install:
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)
