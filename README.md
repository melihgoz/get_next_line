# Get Next Line - Simplified Version

A simplified implementation of the get_next_line project, designed for fresh graduates learning C programming.

## Project Overview

This project reads a line from a file descriptor using the `read()` function from `<unistd.h>`. It returns one line at a time, including the newline character if present.

## Key Features

- **Minimal Functions**: Only 2-3 functions for easy understanding
- **Core Library**: Uses `<unistd.h>` for the `read()` system call
- **Static Variable**: Maintains state between function calls
- **Buffer Management**: Efficiently handles data with configurable BUFFER_SIZE

## Function Count

1. **get_next_line()** - Main function that reads and returns lines
2. **find_newline()** - Helper function to locate '\n' character
3. **join_and_free()** - Static helper to concatenate strings (internal)

## Files

- `get_next_line.h` - Header file with function prototypes
- `get_next_line.c` - Main implementation
- `get_next_line_utils.c` - Helper function (find_newline)
- `main.c` - Test program
- `test.txt` - Sample test file

## How It Works

1. The function uses a **static variable** to store leftover data between calls
2. It reads from the file descriptor using `read()` from `<unistd.h>`
3. Data is accumulated until a newline character is found
4. Returns one complete line (including '\n' if present)
5. Returns NULL when EOF is reached or on error

## Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

## Usage

```bash
./gnl test.txt
```

## Testing

The program will read and display each line from the specified file:

```
Line 1: Hello World!
Line 2: This is a test file.
Line 3: Testing get_next_line function.
...
```

## Key Concepts for Beginners

1. **File Descriptors**: Integer that represents an open file
2. **read()**: System call from `<unistd.h>` that reads bytes from a file
3. **Static Variables**: Retain their value between function calls
4. **Dynamic Memory**: Using `malloc()` and `free()` for flexible memory allocation
5. **Buffer**: Temporary storage area for data being read

## BUFFER_SIZE

You can change the buffer size during compilation:

```bash
gcc -D BUFFER_SIZE=10 ...    # Read 10 bytes at a time
gcc -D BUFFER_SIZE=1000 ...  # Read 1000 bytes at a time
```

## Return Value

- **Success**: Pointer to the line read (caller must free)
- **EOF**: NULL when end of file is reached
- **Error**: NULL if read fails or invalid fd

## Memory Management

- Each returned line must be freed by the caller
- Internal static storage is automatically managed
- No memory leaks when used correctly

---

**Author**: megoz
**42 School Project**: get_next_line
