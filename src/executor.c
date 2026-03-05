#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "../include/executor.h"

void execute_command(Pipeline pipeline){
	int prev_fd=-1;

	for(int i=0;i<pipeline.count;i++){
		int pipefd[2];
		if(i<pipeline.count-1){
			pipe(pipefd);
		}
		pid_t pid =fork();
		if(pid==0){
			if(prev_fd!=-1){
				dup2(prev_fd,STDIN_FILENO);
				close(prev_fd);
			}
			if(i<pipeline.count-1){
				close(pipefd[0]);
				dup2(pipefd[0],STDIN_FILENO);
				close(pipefd[1]);
			}
			execvp(pipeline.commands[i].args[0],pipeline.commands[i].args);
			perror("exec failed");
			exit(1);
		}
		if(prev_fd!=-1){
			close(prev_fd);
		}

		if(i<pipeline.count-1){
			close(pipefd[1]);
			prev_fd=pipefd[0];
		}

	}
	for(int i=0;i<pipeline.count;i++){
		wait(NULL);
	}
}
