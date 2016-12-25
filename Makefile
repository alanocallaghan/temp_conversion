CC = gcc
LIBS = -lm
DEPS = temp_converters.h temp_convert.h 
OBJ = temp_converters.o temp_convert.o
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

temp_convert: $(OBJ) 
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)