/** 
 ** [INSTEAD OF README.md]
 ** This is simple, singlefile 'cat' clone
 ** with same functionality
 **
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 1) {
        write(1, "parameter required\n", 20); /* printing on screen */
        exit(1);
    }

    char* filepath = argv[1]; 

    int fd = open(filepath, O_RDONLY);
    if (fd == -1){
        write(1, "no such file or directory\n", 26); /* printing on screen */
        close(fd);
        exit(1);
    }

    char buffer[1024];
    int read_bytes = read(fd, buffer, 1024);
    while(read_bytes != 0) {
        write(1, buffer, read_bytes);
        read_bytes = read(fd, buffer, 1024);
    }
    close(fd);

    exit(0);
}
