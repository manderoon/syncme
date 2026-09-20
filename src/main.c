#include <stdio.h>
#include <stdlib.h>

#include "data/config.h"
#include "files/dir.h"

int main(int argc, char* argv[]) {

    sync_conf_t sync_conf = {0};

    setup_config(&sync_conf);

    read_dir_name(sync_conf.directory);
}