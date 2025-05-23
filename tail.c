#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    char *path;
    int fd; 
    int lines_count;
    int res;
    off_t file_size;
    int counter;
    char buffer;
    int char_counter;
    int offset;
    if (argc != 3) {
        write(1, "invalid arguments\n", 18);
        exit(0);
    }

    path = argv[1];
    lines_count = atoi(argv[2]);

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        write(1, "invalid arguments\n", 18);
        exit(0);
    }
    
    struct stat file_stat;
    res = fstat(fd, &file_stat);
    
    if(res == -1) {
        write(1, "error\n", 6);
        close(fd);
        exit(0);
    }
    
    file_size = file_stat.st_size;
    char_counter = 0;
    offset = 0;
    counter = 0;
    
    while(counter <= lines_count) {
        offset = file_size - char_counter;
        lseek(fd, offset, SEEK_SET);
        read(fd, &buffer, 1);
        char_counter++;
        if(buffer == '\n') {
            counter++;
        }
    }
    
    counter = 0;
    while(counter <= lines_count) {
        read(fd, &buffer, 1);
        write(1, &buffer, 1);
        if(buffer == '\n') {
            counter++;
        }
    }

    close(fd);
    exit(0);
}
