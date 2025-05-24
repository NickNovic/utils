#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


/*
 * Takes stats about file(now just count of links)
 */

int main(int argc, char **argv) {
    int fd;
    char *path;
    int new_size;


    if(argc != 2) {
        write(1, "invalid arguments count\n", 24);
    }
    
    path = argv[1];
    
    struct stat file_stats;
    stat(path, &file_stats);
    printf("%lu\n", file_stats.st_nlink);
    exit(0);
}
