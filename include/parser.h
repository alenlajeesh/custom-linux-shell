#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 64

typedef struct{
	char *args[MAX_ARGS];
}Command;

Command parse_input(char *input);

#endif
