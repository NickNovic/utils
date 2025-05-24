#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
 * Analog to truncate in standart commands
 */
int main(int argc, char **argv) {
    int fd;
    char *path;
    int new_size;


    if(argc != 3) {
        write(1, "invalid arguments count\n", 24);
    }
    
    path = argv[1];
    new_size = atoi(argv[2]);
    fd = open(path, O_RDWR);
    
    struct stat file_stat;  
    fstat(fd, &file_stat);
    
    ftruncate(fd, new_size);
    close(fd);
    exit(0);
}
