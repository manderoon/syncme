#include "file_util.h"

int read_files(char* directory) {
    DIR *d = opendir(directory); 
    if (d == NULL) {
        printf("Failed to open directory\n");
        return EXIT_FAILURE;
    }

    struct dirent *dir;
    while((dir = readdir(d)) != NULL) {
        if (dir->d_name[0] == '.') {
            continue;
        }
        printf("%s\n", dir->d_name);
    }

    return EXIT_SUCCESS;
}