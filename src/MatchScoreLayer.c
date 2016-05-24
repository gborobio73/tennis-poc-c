#include <pebble.h>
#include "Const.h"
#include "MatchScoreLayer.h"

MatchScoreLayer match_score_layer;

// static void line_layer_update_callback(Layer *layer, GContext* ctx) {
//   graphics_context_set_fill_color(ctx, GColorBlue);
//   graphics_fill_rect(ctx, layer_get_bounds(layer), 0, GCornerNone);
// }

void set_point_layer_design(TextLayer* layer){
	text_layer_set_text_alignment(layer, GTextAlignmentCenter);
	text_layer_set_font(layer, fonts_get_system_font(FONT_KEY_GOTHIC_28));
	//text_layer_set_background_color(layer, GColorClear);
	text_layer_set_text_color(layer, GColorWhite);
	text_layer_set_background_color(layer, GColorBlue);
}

void init_match_score_layer(Layer *window_layer){
	GRect bounds = layer_get_bounds(window_layer);
	//position: new Vector2(82, 51),
    //  size: new Vector2(40, 33),
	match_score_layer.s_text_points_layer[opp] = text_layer_create(GRect(82, 51, 40, 32));
	text_layer_set_text(match_score_layer.s_text_points_layer[opp], "30");
	set_point_layer_design(match_score_layer.s_text_points_layer[opp]);
	// position: new Vector2(82, 84),
 //      size: new Vector2(40, 33),
	match_score_layer.s_text_points_layer[you] = text_layer_create(GRect(82, 84, 40, 32));
	text_layer_set_text(match_score_layer.s_text_points_layer[you], "15");
	set_point_layer_design(match_score_layer.s_text_points_layer[you]);

	match_score_layer.s_text_games_layer[opp] = text_layer_create(GRect(41, 51, 40, 32));
	text_layer_set_text(match_score_layer.s_text_games_layer[opp], "0");
	set_point_layer_design(match_score_layer.s_text_games_layer[opp]);
	
	match_score_layer.s_text_games_layer[you] = text_layer_create(GRect(41, 84, 40, 32));
	text_layer_set_text(match_score_layer.s_text_games_layer[you], "0");
	set_point_layer_design(match_score_layer.s_text_games_layer[you]);

	match_score_layer.s_text_sets_layer[opp] = text_layer_create(GRect(0, 51, 40, 32));
	text_layer_set_text(match_score_layer.s_text_sets_layer[opp], "0");
	set_point_layer_design(match_score_layer.s_text_sets_layer[opp]);
	
	match_score_layer.s_text_sets_layer[you] = text_layer_create(GRect(0, 84, 40, 32));
	text_layer_set_text(match_score_layer.s_text_sets_layer[you], "0");
	set_point_layer_design(match_score_layer.s_text_sets_layer[you]);
	// points_layer.s_layer[opp] = layer_create(GRect(82, 51, 40, 32));
	// layer_set_update_proc(points_layer.s_layer[opp], line_layer_update_callback);
	// points_layer.s_layer[you] = layer_create(GRect(82, 84, 40, 32));
	// layer_set_update_proc(points_layer.s_layer[you], line_layer_update_callback);

	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_points_layer[opp]));
  	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_points_layer[you]));
  	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_games_layer[opp]));
  	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_games_layer[you]));
  	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_sets_layer[opp]));
  	layer_add_child(window_layer, text_layer_get_layer(match_score_layer.s_text_sets_layer[you]));
}

MatchScoreLayer get_match_score_layer(){
	return match_score_layer;
} 

void destroy_match_score_layer(){
	text_layer_destroy(match_score_layer.s_text_points_layer[opp]);	 
	text_layer_destroy(match_score_layer.s_text_points_layer[you]);	 
	text_layer_destroy(match_score_layer.s_text_games_layer[opp]);	 
	text_layer_destroy(match_score_layer.s_text_games_layer[you]);	 
	text_layer_destroy(match_score_layer.s_text_sets_layer[opp]);	 
	text_layer_destroy(match_score_layer.s_text_sets_layer[you]);	 
}