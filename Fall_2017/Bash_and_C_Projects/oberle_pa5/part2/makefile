CC = gcc
CFLAGS = -g -Wall
TARGET = phone
OBJS = phone_fmt.o phone.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
phone_fmt.o: phone_fmt.c
	$(CC) $(CFLAGS) -c phone_fmt.c
phone.o: phone.c
	$(CC) $(CFLAGS) -c phone.c
clean:
	rm -f *.o $(TARGET)
