#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../include/executor.h"

void execute_command(Command cmd){
	pid_t pid =fork();

	if(pid==0){
		execvp(cmd.args[0], cmd.args);
		perror("exec failed");
		exit(1);
	}
	else{
		wait(NULL);
	}
}
