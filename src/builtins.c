#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/builtins.h"

int handle_builtin(Command cmd){
	if(cmd.args[0]==NULL){
		return 1;
	}

	if(strcmp(cmd.args[0],"exit")==0){
		printf("Exiting....");
		exit(0);
	}

	if(strcmp(cmd.args[0],"cd")==0){
		if(cmd.args[1]==NULL){
			printf("cd: missing argument\n");
		}
		else{
			if(chdir(cmd.args[1])!=0){
				perror("cd failed");
			}
		}
		return 1;
	}
	if(strcmp(cmd.args[0],"help")==0){
			printf("myshell built-in commands:\n");
			printf("cd <dir>\n");
			printf("exit\n");
			printf("help\n");
			return 1;
		}
	return 0;
}
