# Makefile for my_shell project

# Compiler and Flags
CC = gcc
CFLAGS = -Wall
GTKFLAGS = `pkg-config --cflags gtk+-2.0`
LIBS = `pkg-config --libs gtk+-2.0`

# Files for my_shell
SHELL_SOURCES = execute_args.c main.c my_cd.c my_env.c my_exit.c my_help.c my_shell_interactive.c my_shell_no_interactive.c new_process.c read_line.c read_stream.c shell_interactive.c split_line.c
SHELL_OBJECTS = $(SHELL_SOURCES:.c=.o)
SHELL_EXECUTABLE = my_shell

# Files for my_shell_gtk
GTK_SOURCES = gtk.c
GTK_OBJECTS = $(GTK_SOURCES:.c=.o)
GTK_EXECUTABLE = my_shell_gtk

all: $(SHELL_EXECUTABLE) $(GTK_EXECUTABLE)

$(SHELL_EXECUTABLE): $(SHELL_OBJECTS)
	$(CC) $(CFLAGS) $(SHELL_OBJECTS) -o $@

$(GTK_EXECUTABLE): $(GTK_OBJECTS)
	$(CC) $(CFLAGS) $(GTKFLAGS) $(GTK_OBJECTS) $(LIBS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

gtk.o: gtk.c
	$(CC) $(CFLAGS) $(GTKFLAGS) -c $< -o $@

clean:
	rm -f $(SHELL_OBJECTS) $(GTK_OBJECTS) $(SHELL_EXECUTABLE) $(GTK_EXECUTABLE)

run:
	./my_shell_gtk

.PHONY: all clean run
# 
