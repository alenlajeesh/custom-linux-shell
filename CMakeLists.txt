cmake_minimum_required(VERSION 3.10)

project(custom_linux_shell)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(cshell 
	src/main.c
	src/parser.c
	src/executor.c
)
