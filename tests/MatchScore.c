#include <stdbool.h>
#include "MatchScore.h"
#include "Const.h"

MatchScore match_score;

int current_score;

void init_match_schore(int who_starts_serving){
    match_score.who_starts_serving=  who_starts_serving;
    current_score =0;
    int scores_zize = sizeof(match_score.scores) / sizeof(match_score.scores[0]);
    
    for (int i = 0; i < scores_zize; ++i)
    {
        match_score.scores[i].is_tie_break = false;
        match_score.scores[i].match_is_over = false;
        match_score.scores[i].sets[opp] = 0;
        match_score.scores[i].sets[you] = 0;
        match_score.scores[i].games[opp] = 0;
        match_score.scores[i].games[you] = 0;
        match_score.scores[i].points[opp] = love;
        match_score.scores[i].points[you] = love;
    }
}

void oponentPoint(){
    match_score.scores[current_score].points[opp] = fifteen;
}

void yourPoint() {
    match_score.scores[current_score].points[you] = fifteen;
}

Score get_current_score(){
    return match_score.scores[current_score];
}

