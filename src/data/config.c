#include "config.h"

int setup_config(sync_conf_t* sync_conf) {

    cfg_opt_t opts[] = {
		CFG_SIMPLE_STR("directory", &sync_conf->directory),
		CFG_SIMPLE_STR("server_ip", &sync_conf->server_ip),
		CFG_SIMPLE_INT("server_port", &sync_conf->server_port),
        CFG_SIMPLE_STR("change_detection_style", &sync_conf->change_detection_style),
        CFG_SIMPLE_INT("checksum_window_size", &sync_conf->checksum_window_size),
		CFG_END()
	};

	cfg_t *cfg;
    cfg = cfg_init(opts, 0);

    if (cfg_parse(cfg, "config.conf") != CFG_SUCCESS) {
        printf("Failure\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
