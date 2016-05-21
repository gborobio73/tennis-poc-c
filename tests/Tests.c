#include <stdio.h>
#include <time.h>
#include <string.h>

#include "MatchScore.h"
#include "Const.h"

void who_starts_serving_test(){
    init_match_schore(opp);

    Score score = get_current_score();
    if (score.who_serves == opp)
    {
        printf("*** who_starts_serving_test PASSED \n"); 
    }else{
        printf("*** who_starts_serving_test FAILED \n");
    }
    
}

void opponent_point_test(){
    init_match_schore(opp);
    
    oponentPoint();

    Score score = get_current_score();

    if (strcmp(score.points[opp], fifteen) == 0)
    {
        printf("*** opponent_point_test PASSED \n"); 
    }else{
        printf("*** opponent_point_test FAILED \n"); 
    }
}

void fifteen_all_test(){
    init_match_schore(opp);
    oponentPoint();
    yourPoint();

    Score score = get_current_score();

    if (strcmp(score.points[opp], fifteen) == 0 && strcmp(score.points[you], fifteen) == 0)
    {
        printf("*** fifteen_all_test PASSED \n"); 
    }else{
        printf("*** fifteen_all_test FAILED \n"); 
    }
}

int main(void)
{
    printf("Running tests.\n");
    who_starts_serving_test();
    opponent_point_test();
    fifteen_all_test();
    //printf("%s \n", ad);
    printf("End of tests.\n");
}
