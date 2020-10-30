SOURCE = $(wildcard *.c)
OBJS = $(SOURCE:.c=.o)
HEADER = $(wildcard *.h)
OUT = project1
ZIP = submission.zip
CC = gcc
CFLAGS = -ggdb -Wall -std=c99
LFLAGS = -lm

all: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(OUT) $(LFLAGS)

clean:
		rm -f $(OBJS) $(OUT) $(ZIP)

zip:
		zip $(ZIP) $(HEADER) $(SOURCE) Makefile
