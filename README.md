# cshell

A minimal Unix shell written in C.

This project demonstrates core operating system concepts such as
process creation, pipes, file descriptors, and job control.

## Features

- Command execution
- Pipes (`|`)
- Input/output redirection (`<`, `>`, `>>`)
- Background processes (`&`)
- Built-in commands (`cd`, `exit`)

## Build

```
make
```

## Run

```
./cshell

```
## Example

cshell> ps | grep bash
cshell> echo hello > file.txt
cshell> sleep 10 &
