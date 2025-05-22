#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * arguments:
 *      path to file to be copied
 *      path to new file location
 */
int main(int argc, char **argv) {
    char *f1_path; 
    char *f2_path;
    char buffer[1024];
    int f1_fd, f2_fd; 
    if (argc != 3) {
        write(1, "enter valid argument\n", 21);
        exit(0);
    }
    
    f1_path = argv[1];
    f2_path = argv[2];
    
    f1_fd = open(f1_path, O_RDONLY); 
    if (f1_fd == -1) {
        write(1, "invalid path\n", 13);
        exit(0);
    }

    f2_fd = open(f2_path, O_WRONLY, O_CREAT | S_IRUSR | S_IWUSR);
    if (f2_fd == -1) {
        write(1, "invalid path\n", 13);
        exit(0);
    }
   
    int char_counter;
    do {
        char_counter = read(f1_fd, buffer, 1024);
        write(f2_fd, buffer, char_counter);
    } while(char_counter != 0);
    
    close(f1_fd);
    close(f2_fd);
}
