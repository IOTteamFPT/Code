CC:=gcc
CFLAGS:= -I./inc

TARGET:= sample

test1.o: src/test1.c
	$(CC) -c $^ -o $@ $(CFLAGS)

test2.o: src/test2.c
	$(CC) -c $^ -o $@ $(CFLAGS)

test3.o: src/test3.c
	$(CC) -c $^ -o $@ $(CFLAGS)

test.o: src/test.c
	$(CC) -c $^ -o $@ $(CFLAGS)
$(TARGET): test.o test1.o test2.o test3.o
	$(CC) $^ -o $@

all: $(TARGET)
clean:	
	rm -f test.o test1.o test2.o test3.o $(TARGET)
