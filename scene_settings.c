// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
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
#include "scene_menu.h"
#include "utility.h"
#include "shared.h"

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.

static ALLEGRO_SAMPLE_ID menuBGM;
static int volumebuttonW ;
static int volumebuttonH ;
static Button btnSettings1;
static Button btnSettings2;
static Button btnSettings3;
static Button homebtn;

static void init() {

	btnSettings1 = button_create(120,500,100,100,"Assets/elsa.png","Assets/anna.png");
	btnSettings2 = button_create(350,500,100,100,"Assets/belle.png","Assets/beast.png");
	btnSettings3 = button_create(620,500,100,100,"Assets/jasmine.jpg","Assets/light.png");
	homebtn = button_create(700,70,80,80,"Assets/homebutton1.png","Assets/homebutton2.png");


	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);

}

static void draw(void){
	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H/3,
		ALLEGRO_ALIGN_CENTER,
		"VOLUME:"
	);

		al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		170,
		SCREEN_H/2,
		ALLEGRO_ALIGN_CENTER,
		"1");

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		400,
		SCREEN_H/2,
		ALLEGRO_ALIGN_CENTER,
		"2");

    al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		670,
		SCREEN_H/2,
		ALLEGRO_ALIGN_CENTER,
		"3");

	drawButton(btnSettings1);
	drawButton(btnSettings2);
	drawButton(btnSettings3);
	drawButton(homebtn);
}


static void on_mouse_down() {
    if (btnSettings1.hovered)
    {
        music_volume=1;
		effect_volume=1;
		stop_bgm(menuBGM);
        menuBGM = play_bgm(themeMusic, music_volume);
    }

    if (btnSettings2.hovered)
    {
        music_volume=3;
		effect_volume=3;
		stop_bgm(menuBGM);
        menuBGM = play_bgm(themeMusic, music_volume);
    }

    if (btnSettings3.hovered)
    {
        music_volume=5;
		effect_volume=5;
		stop_bgm(menuBGM);
        menuBGM = play_bgm(themeMusic, music_volume);
    }

    if (homebtn.hovered)
		game_change_scene(scene_menu_create());
}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	btnSettings1.hovered = buttonHover(btnSettings1, mouse_x, mouse_y);
	btnSettings2.hovered = buttonHover(btnSettings2, mouse_x, mouse_y);
	btnSettings3.hovered = buttonHover(btnSettings3, mouse_x, mouse_y);
	homebtn.hovered = buttonHover(homebtn, mouse_x, mouse_y);
}

static void destroy() {
	stop_bgm(menuBGM);

	al_destroy_bitmap(btnSettings1.default_img);
	al_destroy_bitmap(btnSettings1.hovered_img);
	al_destroy_bitmap(btnSettings2.default_img);
	al_destroy_bitmap(btnSettings2.hovered_img);
	al_destroy_bitmap(btnSettings3.default_img);
	al_destroy_bitmap(btnSettings3.hovered_img);
	al_destroy_bitmap(homebtn.default_img);
	al_destroy_bitmap(homebtn.hovered_img);
}

// The only function that is shared across files.
Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_mouse_move = &on_mouse_move;
	scene.on_mouse_down = &on_mouse_down;
	// TODO: Register more event callback functions such as keyboard, mouse, ...

	game_log("Settings scene created");
	return scene;
}


