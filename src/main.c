#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT 1024
void execute_command(char input[]){
	char *args[64];
	int i=0;
	args[i]=strtok(input," \n");

	while(args[i]!=NULL){
		i++;
		args[i]=strtok(NULL," \n");
	}	

	pid_t pid=fork();

	if(pid==0){
		execvp(args[0], args);
		perror("exec failed");
		exit(1);
	}
	else{
		wait(NULL);
	}
}
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
		execute_command(input);
	}

	return 0;
}
