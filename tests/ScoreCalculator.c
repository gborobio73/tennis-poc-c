#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Const.h"
#include "Score.h"

void copy_score(Score* destination_score, Score* source_score){

	destination_score->is_tie_break = source_score->is_tie_break;
    destination_score->match_is_over = source_score->match_is_over ;
    destination_score->sets[opp] = source_score->sets[opp];
    destination_score->sets[you] = source_score->sets[you];
    destination_score->games[opp] = source_score->games[opp];
    destination_score->games[you] = source_score->games[you];
    destination_score->points[opp] =source_score->points[opp];
    destination_score->points[you] =source_score->points[you];

}

Score* calculate_new_score(Score* current_score, int who_won_the_point){
    Score *new_score = malloc(sizeof(Score));
    //printf("New score with address %p\n", (void*)new_score);
    copy_score(new_score, current_score);
    if (who_won_the_point == opp)
    {
    	new_score->points[opp] =fifteen;
    	//printf("calculate_new_score opponent %p\n", (void*)new_score->points[opp]);
    }else{    	
    	new_score->points[you] =fifteen;
    	//printf("calculate_new_score you %p\n", (void*)new_score->points[you]);
    }
    //printf("about to return new score with address %p\n", (void*)new_score);
    return new_score;
}

