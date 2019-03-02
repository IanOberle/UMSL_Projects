CC = gcc
CFLAGS = -g -Wall
TARGET = wc
TARGET2 = bank
TARGET3 = default
TARGET4 = wc2
OBJS = wc.o
OBJS2 = main.o deposit.o withdrawl.o add_account.o remove_account.o inquiry.o view.o 
OBJS3 = default.o

$(TARGET): $(OBJS) 
	$(CC) -o $(TARGET) $(OBJS)
$(TARGET2): $(OBJS2) 
	$(CC) -o $(TARGET2) $(OBJS2)
$(TARGET3): $(OBJS3)
	$(CC) -o $(TARGET3) $(OBJS3)
$(TARGET4): $(OBJS)
	$(CC) -o $(TARGET4) $(OBJS)

wc.o: wc.c
	$(CC) $(CFLAGS) -c wc.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
deposit.o: deposit.c
	$(CC) $(CFLAGS) -c deposit.c
withdrawl.o: withdrawl.c
	$(CC) $(CFLAGS) -c withdrawl.c
add_account.o: add_account.c
	$(CC) $(CFLAGS) -c add_account.c
remove_account.o: remove_account.c
	$(CC) $(CFLAGS) -c remove_account.c
inquiry.o: inquiry.c
	$(CC) $(CFLAGS) -c inquiry.c
view.o: view.c
	$(CC) $(CFLAGS) -c view.c
default.o: default.c
	$(CC) $(CFLAGS) -c default.c

clean:
	rm -f $(TARGET) $(TARGET2) $(TARGET3) $(TARGET4) $(OBJS) $(OBJS2) $(OBJS3)

