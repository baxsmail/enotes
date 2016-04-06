CC = gcc
CFLAGS = -Wall



all : $(TARGET)


clean :
	rm -f *.o
	rm -f *.exe

SRC := $(wildcard *.c ./src/*.c )
OBJECTS := $(patsubst %.c,%.o,$(SRC))

all: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o test.exe

%: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


$(TARGET) : $(OBJECTS)
	
	$(SRC)
	gcc $(OBJECTS) -o test.exe


