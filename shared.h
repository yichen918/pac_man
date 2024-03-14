// [shared.h]
// you should put shared variables between files in this header.

#ifndef SCENE_SHARED_H
#define SCENE_SHARED_H
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>

// TODO: Shared constant variable (without initializing value).
extern const int FPS;
extern const int SCREEN_H;
extern const int SCREEN_W;
extern const int RESERVE_SAMPLES;
extern const uint32_t GAME_TICK_CD;
extern const char* game_title;
extern const int cage_grid_x,cage_grid_y;
extern const int block_height,block_width;
extern const int map_offset_x,map_offset_y;
extern const int* four_probe;
extern const char*nthu_map;
extern const char*default_map;
extern const int GridSize;
extern const float scale;

// TODO: More shared resources or data that needed to be accessed
// across different scenes. initialize the value in 'shared.c'.;


extern ALLEGRO_FONT* font_pirulen_32;
extern ALLEGRO_FONT* font_pirulen_24;
extern ALLEGRO_SAMPLE* themeMusic;
extern ALLEGRO_SAMPLE* PACMAN_MOVESOUND;
extern ALLEGRO_SAMPLE* PACMAN_DEATH_SOUND;
extern ALLEGRO_FONT* menuFont;
extern int fontSize;
extern int highestscore;
extern float music_volume;
extern float effect_volume;
extern bool gameDone;
extern bool shine;
extern uint64_t shinetime;
extern bool freeze;
extern uint64_t freezetime;



// Initialize shared variables and resources.
// Allows the game to perform any initialization it needs before
// starting to run.
void shared_init(void);
// Free shared variables and resources.
void shared_destroy(void);

#endif
