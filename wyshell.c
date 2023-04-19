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
#include "wyscanner.h"

int main()
{
	char input[1024];
	int token;
	const char* lexeme;

	while (1)
	{
		prinf("wyshell> ");
		fflush(stdout);

		if (fgets(input, sizeof(input), stdin) == NULL)
		{
			exit(0);
		}

		input[strcspn(input, "\n")] = '\0';

		token = parse_line(input);
		while (token != END)
		{
			lexeme = get_lexeme();
			printf("Token: %d, Lexeme: %s\n", token, lexeme);
			token = parse_line(NULL);
		}
	}

	return 0;
}