#include <stdio.h>
#include <stdlib.h>
#include <confuse.h>

int main(int argc, char* argv[]) {

	static cfg_bool_t verbose = cfg_false;

	static char *directory = NULL;
    static char *server_ip = NULL;
	static long int server_port = 0;
	static char *change_detection_style = NULL;
	static long int checksum_window_size = 4096;

    cfg_opt_t opts[] = {
		CFG_SIMPLE_BOOL("verbose", &verbose),
		CFG_SIMPLE_STR("directory", &directory),
		CFG_SIMPLE_STR("server_ip", &server_ip),
		CFG_SIMPLE_INT("server_port", &server_port),
        CFG_SIMPLE_STR("change_detection_style", &change_detection_style),
        CFG_SIMPLE_INT("checksum_window_size", &checksum_window_size),
		CFG_END()
	};

	cfg_t *cfg;

    cfg = cfg_init(opts, 0);

    if (cfg_parse(cfg, "config.conf") != CFG_SUCCESS) {
        printf("Failure\n");
        return EXIT_FAILURE;
    }

    printf("verbose: %s\n", verbose ? "true" : "false");
	printf("server: %s\n", directory);
	printf("username: %s\n", server_ip);
    printf("change_detection_style: %s\n", change_detection_style);
}