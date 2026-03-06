# cshell  
  
A minimal Unix shell written in C.  
  
`cshell` is a small systems programming project designed to demonstrate  
core operating system concepts such as process creation, pipes,  
file descriptor management, and command execution.  
  
This project implements a basic command-line shell capable of executing  
Unix commands, handling pipelines, performing input/output redirection,  
and running background processes.  
  
The goal of this project is educational: to understand how real Unix  
shells like **Bash** work internally.  
  
---  
  
# Features  
  
Current features supported in **v1.0.0**  
  
- Execute external commands  
- Command pipelines (`|`)  
- Input redirection (`<`)  
- Output redirection (`>`)  
- Output append redirection (`>>`)  
- Background process execution (`&`)  
- Built-in commands  
  - `cd`  
  - `exit`  
  
### Example usage  
  
```bash  
cshell> ls  
cshell> ps | grep bash  
cshell> echo hello > file.txt  
cshell> cat < file.txt  
cshell> sleep 10 &  
cshell>
```
---

# Why This Project Exists

Modern shells like **Bash** and **Zsh** are extremely complex.

This project was created to understand the core mechanisms behind them,  
including:

- how processes are created
- how commands communicate using pipes
- how shells redirect input and output
- how background jobs work

By implementing these features manually using low-level system calls,  
this project demonstrates how Unix shells operate internally.

---

# Technologies Used

- **C Programming Language**
- **POSIX system calls**
- **Unix process management**

Key system calls used in this project include:

- `fork()`
- `execvp()`
- `pipe()`
- `dup2()`
- `wait()`
- `open()`

These are fundamental building blocks of Unix systems programming.

---
# Project Structure

```
cshell/  
│  
├── src/  
│   ├── main.c        # shell loop  
│   ├── parser.c      # command parsing  
│   ├── executor.c    # process execution  
│   └── builtins.c    # built-in commands  
│  
├── include/  
│   ├── parser.h  
│   ├── executor.h  
│   └── builtins.h  
│  
├── tests/  
│   └── basic_tests.sh  
│  
├── Makefile  
├── README.md  
└── LICENSE
```
---

# Installation

## Build from Source

Clone the repository:

```
git clone https://github.com/alenlajeesh/custom-linux-shell.git
cd custom-linux-shell
```

Build the project:

```
make
```

Run the shell:

```
./cshell
```
---

## Install Globally (Linux)

You can install `cshell` as a system command.

```
sudo make install
```

After installation:

```
cshell
```
## Example

To uninstall:

```
sudo make uninstall
```

---

# Example Commands

### Running commands

```
shell> ls -l
```

### Pipes

```
shell> ps | grep bash
```

### Output redirection

```
shell> echo hello > file.txt
```

### Input redirection

```
shell> cat < file.txt
```

### Append output

```
shell> echo world >> file.txt
```

### Background process

```
shell> sleep 10 &
```

---

# Testing

Run the test script:

```
./tests/basic_tests.sh
```

This script verifies that the shell can:

- execute commands
- handle pipes
- perform redirection

---

# Learning Outcomes

This project demonstrates several core **Operating System concepts**:

|Concept|Implementation|
|---|---|
|Process creation|`fork()`|
|Program execution|`execvp()`|
|Inter-process communication|`pipe()`|
|File descriptor redirection|`dup2()`|
|Process synchronization|`wait()`|
|File operations|`open()`|

Understanding these concepts is essential for **systems programming**.

---

# Roadmap

Future improvements planned for upcoming versions:

### v1.1

- signal handling (`Ctrl+C`)
- improved error messages

### v1.2

- command history
- arrow key navigation

### v1.3

- tab completion
### v2.0

- full job control (`fg`, `bg`)
- advanced shell features

---

# Contributing

Contributions are welcome.

If you would like to improve the project:

1. Fork the repository
2. Create a new branch
3. Submit a pull request

---
# License

This project is licensed under the **MIT License**.

---
# Acknowledgments

This project was inspired by learning about **Unix shell design**  
and **operating system internals**.

It serves as a practical exercise in systems programming and  
understanding how command-line interfaces work under the hood.

---  
  
If you want, I can also help you make your **README look even more professional** like:  
  
- badges (build, license, language)  
- screenshots / terminal demo  
- animated GIF demo  
- GitHub project banner  
  
These things make your repo look **very professional for recruiters**.
