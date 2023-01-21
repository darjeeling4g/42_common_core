# pipex
> This project is about handling pipes.

## Before start
### 1. access
- Checks the accessibility of the file
- Header file : `#include <unistd.h>`
- Prototype : `int access(const char *path, int mode);`
	- `path` : file name
	- `mode` : the bitwise-inclusive OR of the access permissions to be checked
		> 각 mask들을 or연산으로 대입하여 모두 만족하는지 확인 가능
		- `R_OK` : read permission
		- `W_OK` : write permission
		- `X_OK` : execute/search permission
		- `F_OK` : existence test
- Return values
	- successful completion : 0
	- errno is set to indicate the error : -1

### 2. dup
- duplicates an existing object and returns its value to the calling process
- Header file : `#include <unistd.h>`
- Prototype : `int dup(int fildes);`
	- `fildes` : non-negative integer index in the per-process descriptor table
		> The value must be less than the size of the table, which is returned by gettablesize
- Return values : New descriptor - lowest numbered descriptor crrently not in use by the process

### 3. dup2

### 4. execve

### 5. fork

### 6. pipe

### 7. unlink

### 8. wait

### 9. waitpid

## Mandatory part
|Program name|pipex|
|---|---|
|Turn in files|Makefile, \*.h, \*.c|
|Makefile|NAME, all, clean, fclean, re|
|Arguments|file1 cmd1 cmd2 file2|
|External functs|open, close, read, write, malloc, free, perror, strerror, exit|
||access, dup, dup2, execve, fork, pipe, unlink, wait, waitpid|
|Libft authorized|Yes|

- program will be executed as follow : 
	- `./pipex file1 cmd1 cmd2 file2`
		- It must behave exactly the same as this : `< file1 cmd1 | cmd2 > file2`
	> `file1` & `file2` : file names
	>> `cmd1` & `cmd2` : shell commands with their parameters

### Examples
- `./pipex infile "ls -l" "wc -l" outfile` == `< infile ls -l | wc -l > outfile`
- `./pipex infile "grep a1" "wc -w" outfile` == `< infile grep a1 | wc -w > outfile`

## Bonus part
- Handle multiple pipes
	- `./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2` == `< file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`
- Support `<<` and `>>` when the first parameter is `"here_doc"`
	- `./pipex here_doc LIMITER cmd cmd1 file` == `cmd << LIMITER | cmd1 >> file`
