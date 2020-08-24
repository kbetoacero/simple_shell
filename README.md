# Simple Shell

A simple UNIX command interpreter in order to complete the Simple_Shell project at Holberton School
[flowchart] (https://github.com/kbetoacero/simple_shell/issues/1#issue-684718567)
# Requirements

* Allowed editors: ```vi```, ```vim```, ```emacs```
* All files will be compiled on Ubuntu 14.04 LTS
* C programs and functions will be compiled with ```gcc 4.8.4``` using the flags ```-Wall``` ```-Werror``` ```-Wextra``` and ```-pedantic```
* All your files should end with a new line
* Code should use the ```Betty``` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* No more than 5 functions per file
* Header files should be include guarded

# Current features
+ Run commands in $PATH
+ use "exit" or "ctr + D" to close the program
+ use "cd" to navigate
+ use ls, pwd, with arguments

The shell work in interactive mode:
$ ./kbsh

The shell also works in non-intercative mode:
$ echo "/bin/ls" | ./kbsh


## C Functions and Syscalls Utilized
```
execve (man 2 execve)
exit (man 3 exit)
fork (man 2 fork)
free (man 3 free)
stat (man 2 fstat)
getline (man 3 getline)
malloc (man 3 malloc)
perror (man 3 perror)
strtok (man 3 strtok)
wait (man 2 wait)
```
## Installation
This program was written in **C** and compiled on `Ubuntu 14.04.3 LTS` with `gcc version 4.8.4`

**Clone repo**:
`$ git clone git@github.com:kbetoacero/simple_shell.git`

**Compile**
`$ gcc -Wall -Werror -Wextra -pedantic *.c -o kbsh`

**Instructions**:
#### Execute Commands Within Shell
`$ ./kbsh`

A prompt will follow upon executing `./kbsh` command. <br />
The shell is ready for user input: <br />
`KBSH$ `

# Authors

Carlos A. Acero P.
