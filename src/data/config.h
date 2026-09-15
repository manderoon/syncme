#ifndef CONFIG_H
#define CONFIG_H

#include <stdlib.h>

typedef struct config {
    char* directories;
    char* server_ip;
    int server_port;
    char* change_detection_style;
    size_t checksum_window_size;
} config_t;

int setup_config(char* config_path, config_t* config);

#endif // CONFIG_H
