### - MakeFile - ###
## Trabalho Pratico 2 - Aluno: Francis Carlos dos Santos ##
#compilador
TARGET = tp2
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -std=c99 -pedantic -lm

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
