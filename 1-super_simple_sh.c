#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int _strlen(char *s);
char *create_token(char *s);

/**
 * _strlen - Takes a string as input and returns the lenght.
 *
 * @s: A pointer to an array of characters.
 *
 * Return: The lenght of s.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * create_token - Takes a string as input and returns a token.
 *
 * @s: The string passed to the function.
 *
 * Return: The newly created token.
 */
char *create_token(char *s)
{
	int len = _strlen(s), i = 0;
	char *token;

	token = malloc(len * sizeof(char));
	if (token == NULL)
	{
		perror("Error: Unable to allocate memory\n");
		exit(1);
	}
	while (s[i] != '\n')
	{
		token[i] = s[i];
		i++;
	}
	token[i] = '\0';
	return (token);
}

/**
 * main - a first version of a super simple shell.
 *
 * Description: A super simple shell that can run commands with their full
 * path, without any argument.
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	size_t bufsize = 0;
	char *line = NULL;
	char *args[] = {NULL, NULL, NULL};

	while (1)
	{
		printf("#cisfun$ ");
		if ((getline(&line, &bufsize, stdin)) == -1)
		{
			perror("Error: Unable to read the line\n");
			exit(1);
		}
		printf("%s", line);
		args[0] = create_token(line);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error: Executing in child\n");
			return (1);
		}
		else if (child_pid == 0)
		{
			if ((execve(args[0], args, NULL)) == -1)
			{
				perror("Error: Executing in child\n");
				return (1);
			}
		}
		else
		{
			sleep(1);
			wait(&status);
		}
	}
}
