# 0x16. C - Simple Shell
This repo contains source code files to build a shell. This project was created as part of our course quirements at ALX.

## Concepts covered
* System calls
* File IO
* Creating new processes
* getpid & getppid

## Compiling & running the shell
The shell can be compiled using the command: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

The shell can be run in the interactive and non-interactive mode. To run the shell in the interactive mode you can use the following code:

`$ ./hsh`
`($) /bin/ls` to run the ls command

To run in the non-interactive mode you can use a snippet like

`$ echo "/bin/ls" | ./hsh`
