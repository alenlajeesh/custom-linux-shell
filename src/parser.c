#include <stdio.h>
#include <string.h>
#include "../include/parser.h"

Pipeline parse_input(char *input){
	Pipeline pipeline;
	pipeline.count=0;

	char *pipe_token=strtok(input, "|");
	while(pipe_token!=NULL && pipeline.count <MAX_COMMANDS){
		Command cmd;
		int i=0;
		char *arg =strtok(pipe_token, " \n");
		while(arg!=NULL && i<MAX_ARGS-1){
			cmd.args[i++] =arg;
			arg=strtok(NULL," \n");
		}
		cmd.args[i]=NULL;
		pipeline.commands[pipeline.count++]=cmd;
		pipe_token=strtok(NULL, "|");

	}
	return pipeline;
	
}
