#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc != 3) {
        write(1, "parameter required\n", 20); /* printing on screen */
        exit(1);
    }

    char* old_path = argv[1];
    char* new_path = argv[2];

    int res = rename(old_path, new_path);
    if (res) {
        exit(0);
    }
    
    write(1, "error\n", 6); /* printing on screen */
    exit(1);
}
