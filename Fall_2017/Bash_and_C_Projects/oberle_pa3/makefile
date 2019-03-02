CC = gcc
CFLAGS = -g -Wall
OBJS = main.o avg.o sum.o max.o min.o
OBJS2 = sieve.o
TARGET = operations
TARGET2 = sieve
$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
$(TARGET2): $(OBJS2)
	$(CC) -o $(TARGET2) $(OBJS2)
main.o: main.c avg.h sum.h max.h min.h
	$(CC) -c main.c
avg.o: avg.c
	$(CC) -c avg.c
sum.o: sum.c
	$(CC) -c sum.c
max.o: max.c
	$(CC) -c max.c
min.o: min.c
	$(CC) -c min.c
sieve.o: sieve.c
	$(CC) -c sieve.c
clean:
	rm -f $(OBJS) $(OBJS2) $(TARGET) $(TARGET2)

