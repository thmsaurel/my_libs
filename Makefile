###############################################################################
#
# File Name         : Makefile
# Created By        : Thomas AUREL
# Creation Date     : November 25th, 2014
# Last Change       : January 27th, 2015 at 14:09:54
# Last Change       : January 27th, 2015 at 14:09:54
# Purpose           : It's allow to compile our project easier
#                       - all   : Compile all source presents
#                       - clean : Clean all objects and executable
#
###############################################################################
#### INITIAL PARAMETERS ####
EXECUTABLE= my_printf
SOURCES= main.c my_math.c my_libc.c my_string.c my_stdio.c my_string.1.c my_stdio.1.c
CFLAGS= -Wall -Werror -pedantic -std=c99
LDFLAGS=
CC=gcc
OBJECTS=$(SOURCES:.c=.o)

#### TARGETS ####
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(CFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(SOURCES) $(CFLAGS)

clean:
	rm $(OBJECTS) $(EXECUTABLE)

