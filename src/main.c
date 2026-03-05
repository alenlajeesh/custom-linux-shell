#include <stdio.h>
#include <string.h>
#include "../include/parser.h"
#include "../include/executor.h"

#define MAX_INPUT 1024
int main(){
	char input[MAX_INPUT];

	while(1){
		printf("shell> ");
		if(!fgets(input, MAX_INPUT, stdin)){
			break;
		}
		if(strncmp(input,"exit",4)==0){
			break;
		}
		Command cmd=parse_input(input);
		execute_command(cmd);
	}

	return 0;
}
