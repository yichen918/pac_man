#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>
#include "scene_menu_object.h"
#include "scene_settings.h"
#include "scene_game.h"
#include "scene_win.h"
#include "utility.h"
#include "shared.h"
#include "scene_menu.h"
#include "scene_menu_object.h"


static ALLEGRO_BITMAP* gameover = NULL;
static ALLEGRO_SAMPLE_ID menuBGM;
static int gameoverW;
static int gameoverH;
static Button btnSettings;

static void init() {
    printf("initialized\n");
    //btnSettings = button_create(730,20,50,50,"Assets/settings.png","Assets/settings2.png");
	gameover = load_bitmap("Assets/GAMEOVER.bmp");
	gameoverW = al_get_bitmap_width(gameover);
	gameoverH = al_get_bitmap_height(gameover);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);
}


static void draw() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameoverW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameoverH;

	//draw gameover image
	al_draw_scaled_bitmap(
		gameover,
		0, 0,
		gameoverW, gameoverH,
		offset_w, offset_h,
		gameoverW * scale, gameoverH * scale,0);

        al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\"");
	char str[25];
    sprintf(str,"HIGHEST SCORE : %d",highestscore);
    al_draw_text(menuFont,al_map_rgb(255,150,150),SCREEN_W-400,SCREEN_H-350,ALLEGRO_ALIGN_CENTER,str);

}

static void destroy() {
	stop_bgm(menuBGM);
	al_destroy_bitmap(gameover);
	al_destroy_bitmap(btnSettings.default_img);
	al_destroy_bitmap(btnSettings.hovered_img);
}

static void on_key_down(int keycode) {

	switch (keycode) {
		case ALLEGRO_KEY_ENTER:
			game_change_scene(scene_menu_create());
			break;
		default:
			break;
	}
}

Scene scene_over_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.initialize = &init;
	scene.name = "gameover";
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	//scene.on_mouse_move = &on_mouse_move;
	//scene.on_mouse_down = &on_mouse_down;
	game_log("Gameover scene created");
	return scene;
}
