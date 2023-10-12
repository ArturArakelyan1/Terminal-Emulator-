# Terminal Emulator 💻


## Description

This project is a custom shell implementation that provides both a command-line interface and an integrated GTK-based user interface.
https://medium.com/@artur.araqelyan.0001/developing-terminal-emulator-in-c-9f3d2007e7c1
## Files

| Name | Description |
| ------------------------------ | -------------------------------------------- |
| shell.h | Header file program. |
| main.c | Main function, interactive and non-interactive. |
| new_procees.c | Function that creates a new process. |
| my_cd.c | Change the working directory. |
| my_env.c | Function that prints environment variables. |
| my_exit.c | Exit shell with a given state. |
| my_help.c | Function that prints help (get information about a command) |
| read_line.c | Read a line from stdin. |
| read_stream.c | Read a line from the stream. |
| my_shell_interactive.c | Run shell interactive mode. |
| my_shell_no_interactive.c | Run shell non-interactive mode. |
| split_line.c | Split a string into tokens. |
| execute_args.c | Number of builtin functions. |
## Features

- Custom command-line shell with basic commands.
- Interactive and non-interactive modes.
- GTK-based user interface for a more user-friendly experience.
- Ability to execute system commands and built-in shell commands.

## Requirements

- GCC
- GTK+ 2.0 (for the graphical interface)

## Compilation

The project can be compiled using the provided Makefile:
there are 3 commands 
- make : Build the program
- make run : Run the program
- make clean : Removes all generated files

## List of functions and system calls.

* ```chdir``` (man 2 chdir)
* ```exit``` (man 3 exit)
* ```fork``` (man 2 fork)
* ```free``` (man 3 free)
* ```getline``` (man 3 getline)
* ```isatty``` (man 3 isatty)
* ```malloc``` (man 3 malloc)
* ```perror``` (man 3 perror)
* ```strtok``` (man 3 strtok)
* ```waitpid``` (man 2 waitpid)


## Usage

Interactive mode: ```./my_shell```

Non-interactive mode: ```echo "/bin/ls" | ./my_shell```

### Built-ins

* [x] ```cd```
* [x] ```env```
* [x] ```help```
* [x] ```exit```
* [ ] ```setenv```
* [ ] ```unsetenv```

### Examples



<p>&nbsp</p>

<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://www.linkedin.com/in/santiagobedoa/" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="https://www.linkedin.com/in/santiago-bedoya-arias-852a15233/" height="30" width="40" /></a>
<a href="https://twitter.com/santiagobedoa" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="https://twitter.com/santiagobedoa" height="30" width="40" /></a>
<a href="https://medium.com/@santiagobedoa" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/medium.svg" alt="https://medium.com/@santiagobedoa" height="30" width="40" /></a>
</p>
<p></p>
