#include <faulty.h>

char *get_path_for_file(const char *dir, uint8_t id, const char *extension) {
    // ASSUMPTION: id length is 3 characters max, because it's a uint8_t.
    //             If id's type is changed, that value changes, too.
    size_t file_name_max_length = strlen(dir) + 3 /* id length */ + strlen(extension);
    char *file_path = malloc(file_name_max_length);
    memset(file_path, 0, file_name_max_length);
    snprintf(file_path, file_name_max_length, "%s%hhu%s", dir, id, extension);

    return file_path;
}
