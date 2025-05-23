#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * arguments:
 *      path to file
 *      lines count
 */

int main(int argc, char **argv) {
    char *path;
    char buffer;
    int lines_count;
    int lines_read; 
    int fd;
    int counter;

    if (argc != 3) {
        write(1, "enter valid args\n", 17);
        exit(0);
    }

    path = argv[1];
    lines_count = atoi(argv[2]);
    if (lines_count == 0) {
        write(1, "enter valid count of lines\n", 28);
        exit(0);
    }

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        write(1, "invalid path\n", 13);
        exit(0);
    }
    
    counter = 0;
    while (counter < lines_count && lines_read != 0) {
        lines_read = read(fd, &buffer, 1);
        write(1, &buffer, 1);
        if (buffer == '\n') {
            counter++;
        }
    }
    close(fd);
}
