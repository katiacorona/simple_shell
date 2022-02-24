# :shell: Simple Shell

## Background Context

Write a simple UNIX command interpreter.

## Compilation and Testing

Our shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

Interactive mode:

`$ ./hsh \
($) /bin/ls \
hsh main.c shell.c \
($) \
($) exit \
$`

Non-interactive mode:

`$ echo "/bin/ls" | ./hsh \
hsh main.c shell.c test_ls_2 \
$ \
$ cat test_ls_2 \
/bin/ls \
/bin/ls \
$ \
$ cat test_ls_2 | ./hsh \
hsh main.c shell.c test_ls_2 \
hsh main.c shell.c test_ls_2 \
$`
