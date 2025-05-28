#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argv) {
    int fd;
    char *path;

    if (argc == 1) {
        write(1, "parameter required\n", 20); /* printing on screen */
        exit(1);
    }
    
    path = argv[1];
    unlink(path);
    exit(0);
}
