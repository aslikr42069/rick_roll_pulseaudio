CC      = gcc
CFLAGS  = -O2 -lpulse -lm -lpulse-simple -Wall -Wextra -Wpedantic
INFILE  = main.c
OUTFILE = play

default:
	$(CC) $(CFLAGS) $(INFILE) -o $(OUTFILE)
