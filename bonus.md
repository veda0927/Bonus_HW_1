 Blazerid: vmakkapa

 # Table of Contents

- [Table of Contents](#table-of-contents)
   - [Project title](#Project-title)
   - [Project Description](#Project-Description) 
   - [Author](#Author) 
   - [Acknowledgment](#Acknowledgment) 
   - [Getting Started](#Getting-Started) 
   - [Running the test](#Running-the-test)
   -[Screenshots/Sample Session](#Screenshot-sample-session)

## Project title

Implement a simple shell or command line interpreter

## Project Description

The main source file in the shel is named as shell.c
In this the shell will be continously running and it will be displaying the prompt until it is waiting for the input. While this is invoking by the excutable file after that it will waiting be providing a prompt showing uab_sh> and waiting for thr input. 
The uab_sh> will be reading a line from the stdin one at a time and this line will be parsing out into the command and argument after parssing each line it will be executed.
It creates the new process that is corresponding to the input entered. we can enter a newline character without any other text the shell will just display the prompt on the next new line. 

## Author

Veda Mounica Makkapati

## Getting started

 - Prerequisites
   Visual Studio
   Putty
   Cisco Anyconnect
   C complier
 - Instructions for building the software 
   All the application that are used can be downloaded from the internet and then continue to installation. The user needs ti signin with the credentials that are provided in cisco to access the Vulcan server. 

## Running the test

"make" this command to compile the code and displays
gcc -g -o -Wall -o uab_sh shell.c

for running 
./uab_sh

## Screenshots/Sample Session 

uab_sh> hello
Hello World!

uab_sh> fibonacii 10

Status <255>

uab_sh> fibonacci 10
 -> 0, 1, 1, 2, 3, 5, 8, 13, 21, 34

uab_sh> fibonacci

How many elements you want to display: 7
 -> 0, 1, 1, 2, 3, 5, 8
 
 uab_sh> help
- You can run every Bash Command Here. Some user defined commands are,
 a. hello - Prints Greeting 'Hello World!'.
 b. fibonacci <value> - calculate fibonacci number with given value.
 c. list - list all the files in the current directory. The default directory is the directory where the shell program was invoked
 d. cd <directory> - change the current directory to the <directory>. The default directory would be the directory where the shell program was invoked
 e. help - display the internal commands and a short description on how to use them.
 f. history - shows history commands.
 g. quit - quit the shell program

 uab_sh> history
Command History : (10 in total)
 1 : hello
 2 : fibonacii
 3 : fibonacci
 4 : fibonacci
 5 : list
 6 : pwd
 7 : cd
 8 : pwd
 9 : help
 10 : history

 uab_sh> ps
  PID TTY          TIME CMD
    8 tty1     00:00:00 init
   34 tty1     00:00:00 sudo
   35 tty1     00:00:20 bash
 9936 tty1     00:00:00 a.out
 9941 tty1     00:00:00 ps

Status <0>
uab_sh> quit