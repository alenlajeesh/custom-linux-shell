#include <stdio.h>
#include <string.h>
#include "../include/parser.h"

Command parse_input(char *input){
	Command cmd;
	int i=0;

	char *token=strtok(input," \n");

	while(token!=NULL && i<MAX_ARGS -1){
		cmd.args[i++] =token;
		token =strtok(NULL," \n");
	}
	cmd.args[i]=NULL;
	return cmd;
}
