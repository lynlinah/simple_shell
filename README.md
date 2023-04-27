## Simple_Shell
> In this project, we coded  A Unix style shell, an interactive which command-line interpreter. We created a shell that would utilize the command line
> interface (CLI). It allows users to type in a set of commands and task the operating system to run the appropriate function. 
> 
 There are a few versions of Unix shells, from the very first (Ken Thompson's) shell that can
> be activated by typing ```sh``` in the terminal to today's most popular(Bourne Again Shell) a.k.a Bash
> There are improved versions of the shell that handle memory leaks better and have more functionality. Our shell is a simple version that
 has basic functionality. You can create/write/read/open/remove folders, print things to the terminal, 


### Synopsis
> This repository holds all the code necessary for our custom simple shell to run.
> Our shell currently handles the executions of executables found in the
> Environment variable PATH, with or without their full paths. 

### Builtins
* ```exit``` e xits shell (```Usage: exit [status]```)
* ```env``` prints Environment variables (Usage: ```env```)
* ```setenv``` creates or modifies an Environment variable (Usage: ```setenv name value```)
* ```unsetenv``` removes an envrionmental variable (Usage: ```unsetenv name value```)
* ```cd``` changes directories (Usage: ```cd [-][~][path]```)

### Functions and system calls used
```read```, ```signal```, ```malloc```, ```free```, ```getcwd```, ```chdir```, ```access```, ```execve```, ```wait```, ```write```,  ```exit```

### Description of what each file shows:
```
main.c ----------------------------- holds entrance into program
shell.h ---------------------------- holds prototypes of functions spread across all files
```
Helper files
```
prompt.c --------------------------- handles outline of shell's reprompting and executing
non_interactive.c ------------------ handles output when shell is called outside of shell
_realloc.c ------------------------- helper function handles reallocation
_strcat.c -------------------------- concatenates two strings
_strcmp.c -------------------------- compares if two strings match
_strcpy.c -------------------------- copies a string
_strdup.c -------------------------- duplicates a string
_str_tok.c -------------------------- (custom) tokenizes user's command input and returns array
c_str_tok.c ------------------------- tokenizes PATH to include ":" as Null, checks current dir
get_line.c ------------------------- (custom) reads user's typed input into buffer
_which.c --------------------------- appends command to PATHs, fleshes paths out, returns match
_cd.c ------------------------------ changes directories
linked_lists.c --------------------- adds and deletes nodes; prints and frees linked list
get_env.c -------------------------- finds and returns copy of Environment variable
env_linked_list.c ------------------ prints and creates linked list of envrionmental variables
set_unset_env.c -------------------- finds environment variable index node, sets and unsets
free_double_ptr -------------------- frees double pointers (user's command, arrays)
_execve.c -------------------------- executes and frees command, then exits program
__exit.c --------------------------- handles if user types exit or exit(value)
int_to_string.c -------------------- converts int to string to write error messages
print_error.c ---------------------- prints special error messages for certain fails
```
### Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 
* Style guidelines: [Betty style]

## How To Install, Compile, and Use
Install and Compile
```
(your_terminal)$ git clone https://github.com/lynlinah/simple_shell.git
(your_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -Wno-format *.c -o simple_shell

```
**Interactive Mode***
Activate the shell
```
(your_terminal)$ ./simple_shell
**Non-Interactive Mode**
```
echo "ls -l" | ./simple_shell
```


---
### Authors
Lewis Wangui (https://twitter.com/LWakahenya)
Caroline Njeru (https://twitter.com/linah8590)
