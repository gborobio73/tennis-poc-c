#include <pebble.h>

#ifndef MATCHSCORELAYER_H
#define MATCHSCORELAYER_H

typedef struct 
{
	TextLayer *s_text_points_layer[2];
	TextLayer *s_text_games_layer[2];
	TextLayer *s_text_sets_layer[2];
	// Layer *s_layer[2];
} MatchScoreLayer;

void init_match_score_layer(Layer* );
void destroy_match_score_layer();

MatchScoreLayer get_match_score_layer(); 

#endif