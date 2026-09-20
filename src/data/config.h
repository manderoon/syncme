#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>
#include <confuse.h>

typedef struct sync_conf {
    char* directory;
    char* server_ip;
    long int server_port;
    char* change_detection_style;
    long int checksum_window_size;
} sync_conf_t;

int setup_config(sync_conf_t* sync_conf);

#endif // CONFIG_H
