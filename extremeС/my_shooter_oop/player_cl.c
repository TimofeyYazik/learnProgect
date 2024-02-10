#include <stdlib.h>
#include <string.h>
#include "gun_cl.h"

typedef struct player_t{
    char name[20];
    struct gun_t *gun;
}player_t;

player_t* player_init(){
    player_t *player = malloc(sizeof(player_t));
    return player;
}
void player_ctor(player_t* player, char* name){
    strcpy(player->name, name);
    player->gun = (void*)0;
}

void player_set_gun(player_t* player, struct gun_t* gun){
    player->gun = gun;
}

void player_shoot(player_t* player){
    gun_shoot(player->gun);
}

void player_change_gun(player_t* player, struct gun_t* gun){
    player->gun = (void*)0;
    player_set_gun(player, gun);
}

void player_drop_gun(player_t* player){
    player->gun = (void*)0;
}

void player_destroy(player_t* player){
    free(player);
}





