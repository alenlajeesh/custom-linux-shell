#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 64
#define MAX_COMMANDS 10

typedef struct{
	char *args[MAX_ARGS];
}Command;

typedef struct{
	Command commands[MAX_COMMANDS];
	int count;
}Pipeline;

Pipeline parse_input(char *input);

#endif
