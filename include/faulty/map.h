#ifndef FAULTY_MAP_H
#define FAULTY_MAP_H

typedef struct map_s {
    Tile *tiles;
} Map;

Map *new_map();
bool clear_map(Map *map);
bool load_map(Map *map, uint8_t map_id);

#endif
