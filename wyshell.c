/*
 * wyshell.c
 * Author : Cole Sigmon
 * Date : April 18, 2023
 * 
 * COSC 3750, Homework 8
 * 
 * This is wyshell.c it is a beginning of a shell.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wyscanner.h"

int main()
{
	char input[1024];
	int token;
	int piped = 1;

	while (1)
	{
		printf("$> ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			exit(0);
		}

		input[strcspn(input, "\n")] = '\0';
		
		token = parse_line(input);
		while (token != NULL)
		{
			if (token == ERROR_CHAR)
			{
				perror("error character: ");
				perror(error_char);
			}
			else if (token == SYSTEM_ERROR)
			{
				perror("system error");
				return 0;
			}
			else if (token == QUOTE_ERROR)
			{
				perror("quote error");
			}
			else
			{
				if (token != 200)
				{
					if (token == 107)
					{
						printf(" |\n");
					}
					else if (token == 100)
					{
						printf(" >\n");
					}
					else
					{
						printf(" %d\n", token);
					}
					piped = 1;
				}
				else if (lexeme == ':')
				{
					printf(" :");
					piped = 1;
				}
				else if (piped == 1)
				{
					printf(":--: %s\n", lexeme);
					piped = 0;
				}
				else
				{
					printf(" --: %d %s\n", token, lexeme);
				}
			}
			token = parse_line(NULL);
		}
		printf(" --: EOL\n");
		piped = 1;
	}

	return 0;
}
