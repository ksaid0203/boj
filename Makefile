CC=g++
CFLAGS= -O2 -Wall -lm -static -std=gnu++11
OBJS=14948.o
TARGET=a.out
$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o
	rm -f $(TARGET)

