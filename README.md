This document outlines the details of a simple UNIX shell project created by Daniel Chebet  who is a students in the ALX Software Engineering program. The project is named "Simple Shell" and is based on the functionality of the bash and Sh shells.

---

# Simple Shell Project

The **Simple Shell** is a basic command interpreter for UNIX-like systems, inspired by both bash and Sh shells.

## Overview

The Simple Shell acts as a command language interpreter that reads and executes commands from standard input or files.

### Invocation

To start using the Simple Shell, compile all `.c` files in the repository with the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
./hsh
```

The Simple Shell can be invoked interactively or non-interactively. When standard input is not connected to a terminal, it executes received commands. For instance:

```bash
$ echo "echo 'school'" | ./hsh
'school'
```

When standard input is connected to a terminal, interactive mode is opened with the prompt `^-^ `.

### Environment

Upon invocation, the Simple Shell copies the parent process's environment. Key environmental variables include:

- `HOME`: Home directory of the current user.
- `PWD`: Current working directory.
- `OLDPWD`: Previous working directory.
- `PATH`: Colon-separated list of directories for command search.

### Command Execution

The Simple Shell tokenizes commands into words using spaces as delimiters. It then performs the following actions:

1. If the command is a builtin, it's invoked.
2. If not, it searches for the command in the directories listed in `PATH`.
3. If found, it executes the program with given arguments.

### Exit Status

The shell returns the exit status of the last executed command. Zero indicates success, and non-zero indicates failure. Return status is 127 for command not found and 126 for found but non-executable commands. Builtin commands return 0, 1, or 2 for incorrect usage.

### Signals

In interactive mode, the Simple Shell ignores ctrl+c but exits with ctrl+d (End-Of-File).

### Variable Replacement

The `$` character is used for variable replacement:

- `$ENV_VARIABLE`: Replaced with its value.
- `$?`: Replaced with the return value of the last command.
- `$$`: Replaced with the current process ID.

### Comments

Lines beginning with `#` are treated as comments and ignored.

### Operators

Special interpretation for these operators:

- `;`: Executes commands sequentially.
- `&&`: Executes the second command if the first succeeds.
- `||`: Executes the second command if the first fails.

### Builtin Commands

- `cd`: Change directory.
- `exit`: Exit the shell.
- `env`: Print current environment.
- `setenv`: Initialize or modify environment variables.
- `unsetenv`: Remove environment variables.

## Author & Copyrights

Author Daniel Chebet 

