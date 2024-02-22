CC=gcc
CFLAGS=-O3 -std=c99 -w -g
TARGET=zacastle
all: $(TARGET)

$(TARGET): zacastle.c
	$(CC) zacastle.c $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
