#include <pebble.h>
#include "Const.h"
#include "MatchScoreLayer.h"
#include "MatchScore.h"
#include "Score.h"

static Window *window;

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
	cancel_last_point();
	Score* score = get_current_score();	
	match_score_layer_draw_score(score);
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
	oponentPoint();
	Score* score = get_current_score();	
	match_score_layer_draw_score(score);
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
	yourPoint();
	Score* score = get_current_score();	
	match_score_layer_draw_score(score);
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  
  init_match_score_layer(window_layer);

  init_match_schore(opp, 3);
  Score* score = get_current_score();

  match_score_layer_draw_score(score);

}

static void window_unload(Window *window) {
  	destroy_match_score_layer();

  	end_match();
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
