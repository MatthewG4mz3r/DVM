CC     = gcc
CFLAGS = -O1 -Wall -Wextra -std=c11 -pedantic
exec   = DVM
LIBS   = 

DVM:
	$(CC) $(CFLAGS) -o $(exec) src/*.c $(LIBS)
