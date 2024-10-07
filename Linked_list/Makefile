CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = link_list.o list.o
TARGET = link_list


all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c list.h
	$(CC) $(CFLAGS) -c $<  


.PHONY: clean
clean:
	rm -Rf $(TARGET) $(OBJ)