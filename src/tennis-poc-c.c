#include <pebble.h>
#include "Const.h"
#include "MatchScoreLayer.h"

static Window *window;
static TextLayer *text_layer;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Select");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Up");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "Down");
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  

  init_match_score_layer(window_layer);

  // text_layer = text_layer_create(GRect(0, 72, bounds.size.w, 20));
  // text_layer_set_text(text_layer, "Press a button");
  // text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  
  // layer_add_child(window_layer, points_layer.s_layer[opp]);
  // layer_add_child(window_layer, points_layer.s_layer[you]);

  
}

static void window_unload(Window *window) {
  	destroy_match_score_layer();
	// layer_destroy(points_layer.s_layer[opp]);
	// layer_destroy(points_layer.s_layer[you]);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  //APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
