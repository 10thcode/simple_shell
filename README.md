# 0x16. C - Simple Shell
This repo contains source code files to build a shell. This project was created as part of our course quirements at ALX.

## Features of the shell
The program enables users to perform basic shell commands effectively. 

* Appropriate error messages are displayed to help users interact with the shell
* Effective memory management
* Command PATH lookup

## Concepts covered
* System calls
* File IO
* Creating new processes
* getpid & getppid
* Variadic functions
* Singly-linked lists

## Compiling & running the shell
The shell can be compiled using the command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

The shell can be run in the interactive and non-interactive mode. To run the shell in the interactive mode you can use the following code:

`$ ./hsh`
`($) /bin/ls` to run the ls command
`($) ls` to run the ls command as well. The shell would look up the path to the command the user provided

To run in the non-interactive mode you can use a snippet like

`$ echo "/bin/ls" | ./hsh`
