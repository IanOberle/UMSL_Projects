CC = gcc
CFLAGS = -g -Wall
TARGET = deater
OBJS = main.o func.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
func.o: func.c
	$(CC) $(CFLAGS) -c func.c
clean:
	rm -f *.o $(TARGET)
