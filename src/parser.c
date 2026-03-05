#include <string.h>
#include "../include/parser.h"

Pipeline parse_input(char *input)
{
    Pipeline pipeline;
    pipeline.count = 0;
    char *save_pipe;
    char *pipe_token = strtok_r(input, "|", &save_pipe);
    while (pipe_token != NULL && pipeline.count < MAX_COMMANDS)
    {
        Command cmd;
        int i = 0;
        char *save_arg;
        char *arg = strtok_r(pipe_token, " \n", &save_arg);

        while (arg != NULL && i < MAX_ARGS - 1)
        {
            cmd.args[i++] = arg;
            arg = strtok_r(NULL, " \n", &save_arg);
        }
        cmd.args[i] = NULL;
        pipeline.commands[pipeline.count++] = cmd;
        pipe_token = strtok_r(NULL, "|", &save_pipe);
    }
    return pipeline;
}
