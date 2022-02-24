# :shell: Simple Shell

## Background Context

Write a simple UNIX command interpreter.

## Compilation and Testing

Our shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

Interactive mode:

```
$ ./hsh<br />
($) /bin/ls<br />
hsh main.c shell.c<br />
($)<br />
($) exit<br />
$
```

Non-interactive mode:

```
$ echo "/bin/ls" | ./hsh<br />
hsh main.c shell.c test_ls_2<br />
$<br />
$ cat test_ls_2<br />
/bin/ls<br />
/bin/ls<br />
$<br />
$ cat test_ls_2 | ./hsh<br />
hsh main.c shell.c test_ls_2<br />
hsh main.c shell.c test_ls_2<br />
$
```
