#include <stdio.h>
#include "../include/parser.h"
#include "../include/executor.h"
#include "../include/builtins.h"

#define MAX_INPUT 1024

int main()
{
    char input[MAX_INPUT];
    while (1)
    {
        printf("shell> ");
        if (!fgets(input, MAX_INPUT, stdin))
            break;
        Pipeline pipeline = parse_input(input);
        if (pipeline.count == 1)
        {
            if (handle_builtin(pipeline.commands[0]))
                continue;
        }
        execute_pipeline(pipeline);
    }
    return 0;
}
