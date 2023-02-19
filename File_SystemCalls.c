//1.Introduction to system calls – implementation of open(), creat(),close(), write(), read(), lseek().
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() 
{
    int fd;
    char *text = "Hello, World!";
    char buffer[100];

    // Open file "file.txt" with read and write permissions
    fd = open("file.txt", O_RDWR | O_CREAT, 0666);

    // Write text to the file
    write(fd, text, strlen(text));

    // Set the file offset to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read the contents of the file into the buffer
    read(fd, buffer, strlen(text));

    // Print the contents of the buffer
    printf("Read from file: %s\n", buffer);

    // Close the file
    close(fd);

    return 0;
}
