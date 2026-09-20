#include <stdio.h>
#include <stdlib.h>

#include "data/config.h"
#include <dirent.h>

int main(int argc, char* argv[]) {

    sync_conf_t sync_conf = {0};

    setup_config(&sync_conf);

    // Read from directory
    DIR *d = opendir(sync_conf.directory); 
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
}