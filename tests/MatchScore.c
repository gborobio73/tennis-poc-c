#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "MatchScore.h"
#include "Const.h"
#include "ScoreCalculator.h"

MatchScore match_score;

static int current_score;

void init_match_schore(int who_starts_serving){
    match_score.who_starts_serving=  who_starts_serving;
    current_score =0;

    match_score.scores[current_score] = (Score *)malloc(sizeof(Score));
    match_score.scores[current_score]->is_tie_break = false;
    match_score.scores[current_score]->match_is_over = false;
    match_score.scores[current_score]->sets[opp] = 0;
    match_score.scores[current_score]->sets[you] = 0;
    match_score.scores[current_score]->games[opp] = 0;
    match_score.scores[current_score]->games[you] = 0;
    match_score.scores[current_score]->points[opp]=love;
    match_score.scores[current_score]->points[you]=love;
    match_score.scores[current_score]->tie_break_points[opp]=0;
    match_score.scores[current_score]->tie_break_points[you]=0;
}

void oponentPoint(){    
    Score* new_score = calculate_new_score(match_score.scores[current_score], opp);
    
    current_score++;

    match_score.scores[current_score]= new_score;
}

void yourPoint() {
    //printf("your point start \n");
    Score* new_score = calculate_new_score(match_score.scores[current_score], you);
    //printf("your point got new score \n");
    current_score++;

    match_score.scores[current_score]= new_score;
    //printf("your point end \n");
}

Score* get_current_score(){
    //printf("get_current_score start \n");
    //printf("get_current_score start %d\n", current_score);
    return match_score.scores[current_score];
}

void end_match(){
    //printf("end_match start \n");
    for (int i = 0; i <= current_score; ++i)
    {
        free(match_score.scores[i]);
    }
    current_score =0;
    //printf("end_match end \n");
}

