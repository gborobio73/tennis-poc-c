#include "Score.h"

typedef struct
{
    int who_starts_serving;
    Score scores [100];
} MatchScore;

void init_match_schore(int);
void oponentPoint();
void yourPoint();
Score get_current_score();