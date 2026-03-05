#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "../include/executor.h"
void execute_pipeline(Pipeline pipeline)
{
    int prev_fd = -1;
    for (int i = 0; i < pipeline.count; i++)
    {
        int pipefd[2];
        if (i < pipeline.count - 1){
			if(pipe(pipefd)<0){
				perror("pipe");
				exit(1);
			}
		}
        pid_t pid = fork();
		if(pid<0){
			perror("fork");
			exit(1);
		}
        if (pid == 0)
        {
            Command cmd = pipeline.commands[i];
            if (prev_fd != -1)
            {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }
            if (i < pipeline.count - 1)
            {
                close(pipefd[0]);
                dup2(pipefd[1], STDOUT_FILENO);
                close(pipefd[1]);
            }
            if (cmd.input_file != NULL)
            {
                int fd = open(cmd.input_file, O_RDONLY);
                if (fd < 0)
                {
                    perror("open input file");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
            if (cmd.output_file != NULL)
            {
                int fd;
                if (cmd.append)
                {
                    fd = open(
						cmd.output_file,
                        O_WRONLY | O_CREAT | O_APPEND,
                        0644
					);
                }
                else
                {
                    fd = open(
						cmd.output_file,
                        O_WRONLY | O_CREAT | O_TRUNC,
                        0644
					);
                }
                if (fd < 0)
                {
                    perror("open output file");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            execvp(cmd.args[0], cmd.args);
            perror("exec failed");
            exit(1);
        }

        if (prev_fd != -1)
            close(prev_fd);
        if (i < pipeline.count - 1)
        {
            close(pipefd[1]);
            prev_fd = pipefd[0];
        }
    }
	int background = pipeline.commands[pipeline.count-1].background;

	if(!background){
    for(int i=0;i<pipeline.count;i++)
        wait(NULL);
	}
	else{
		printf("[running in background]\n");
	}    
}
