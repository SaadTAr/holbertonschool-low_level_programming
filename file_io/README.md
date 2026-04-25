# File I/O Project

## Description
This project is about low-level file input/output using system calls in C.

## Tasks

### 0. read_textfile
Function that reads a text file and prints it to the POSIX standard output.

Prototype:
ssize_t read_textfile(const char *filename, size_t letters);

- Reads up to "letters" bytes from a file
- Prints to STDOUT
- Returns number of bytes printed
- Returns 0 on failure
