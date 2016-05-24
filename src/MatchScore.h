#include "Score.h"
#ifndef MATCHSCORE_H
#define MATCHSCORE_H

typedef struct
{
    Score* scores [100];
} MatchScore;

void init_match_schore(int, int);
void end_match();
void oponentPoint();
void yourPoint();
Score* get_current_score();
void cancel_last_point();
int amount_of_scores();

#endif