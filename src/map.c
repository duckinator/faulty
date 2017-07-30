#include <faulty.h>

static Map *map = NULL;

void clear_map() {
    free(map);
    map = NULL;
}

bool load_map(char *File) {
    clear_map();

    return true;
}
