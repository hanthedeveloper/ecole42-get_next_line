*This project has been created as part of the 42 curriculum by haincel.*

# Get Next Line

## Description

Get Next Line is a C project from the 42 core curriculum. Its goal is to
write a function that reads a text file (or any file descriptor) line by
line, one call at a time, without relying on any function that reads a
file all at once. The result is a small, self-contained `get_next_line`
function that can be reused as a foundation in later C projects
throughout the curriculum.

## Instructions

Compile the project from the `get_next_line` folder after writing a main.c:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

The `BUFFER_SIZE` macro controls how many bytes are read from the file at
each `read` call, and can be set to any value at compile time.

Run the resulting binary:

```sh
./gnl
```

By default `main.c` opens a file named `dosya.txt` in the same directory
and prints it out line by line using `get_next_line`.

## Project contents

- **Core function:** `get_next_line` — returns the next line of a file
  descriptor each time it is called, including the trailing newline, and
  `NULL` once the end of the file is reached.
- **Internal helper:** `has_new_line` — checks the buffered content held
  between calls for a newline and splits off the next line when found.
- **Utility functions:** `ft_strlen`, `ft_strdup`, `ft_substr`, `ft_strchr`,
  `ft_strjoin` — small string/memory helpers reimplemented locally to keep
  the project self-contained.

## Resources

- `man 2 read` and `man 3` pages for the functions used in this project.
- The C standard library documentation at https://man7.org/linux/man-pages/.
- The official 42 project subject and the 42 Norm document.

## AI usage

AI was used to fill in the gaps in
the subject PDF where it lacked details. It was not used to write the
function implementations themselves.
