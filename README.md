*This project has been created as part of the 42 curriculum by SWETTING*

Description:

The function returns a string that contains all characters until the newline character or end of the file whichever is reached first. It stores everything read from the file into the buffer after the newlin character. So that it can be concatenated to the returned string when the function is called again. When the functions is called again it will try to return the next characters until the newline/EOF is reached.

instructions:
compile and run using:

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 *.c; ./a.out

Resources:

I reused and edited some functions of LibFT. Asked my peers for help sometimes. GNL was mainly tested by the Francinette. The program was mainly debugged by using the debugger, except for finding leaks. Valgrind was used for finding the leaks. Though it was still hard to find them.