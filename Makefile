CC = gcc
LIBS = -lm
DEPS = temp_conversion.h hello_world.h 
OBJ = temp_conversion.o hello_world.o
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hello_world: $(OBJ) 
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)