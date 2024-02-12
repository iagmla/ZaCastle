CC=gcc
CFLAGS=-O3 -std=c99 -w
TARGET=zacastle
all: $(TARGET)

$(TARGET): zacastle.c
	$(CC) zacastle.c $(CFLAGS) -o $(TARGET)

clean:
	$(RM) $(TARGET)
