#include <stdio.h>
#include <time.h>
#include <string.h>

#include "MatchScore.h"
#include "Const.h"

void who_starts_serving_test(){
    //printf("*** who_starts_serving_test STARTED\n");
    init_match_schore(opp);

    Score* score = get_current_score();
    if (score->who_serves == opp)
    {
        printf("*** who_starts_serving_test PASSED \n"); 
    }else{
        printf("*** who_starts_serving_test FAILED \n");
    }
    
    end_match();
    //printf("*** who_starts_serving_test ENDED\n\n");
}

void opponent_point_test(){
    //printf("*** opponent_point_test STARTED\n");
    init_match_schore(opp);
    
    oponentPoint();

    Score* score = get_current_score();
    //printf("*** opponent_point_test pointes %s\n", score->points[opp]);
    if (strcmp(score->points[opp], fifteen) == 0)
    {
        printf("*** opponent_point_test PASSED \n"); 
    }else{
        printf("*** opponent_point_test FAILED \n"); 
    }
    end_match();
    //printf("*** opponent_point_test ENDED\n\n");
}

void fifteen_all_test(){
    //printf("*** fifteen_all_test STARTED\n");
    init_match_schore(opp);
    oponentPoint();
    yourPoint();

    Score* score = get_current_score();
    /*
    printf("*** fifteen_all_test got current score address %p\n", (void*) score);
    printf("*** fifteen_all_test points %s\n", score->points[opp]);
    printf("*** fifteen_all_test points you%s\n", score->points[you]);
*/
    if (strcmp(score->points[opp], fifteen) == 0 && strcmp(score->points[you], fifteen) == 0)
    {
        printf("*** fifteen_all_test PASSED \n"); 
    }else{
        printf("*** fifteen_all_test FAILED \n"); 
    }
    end_match();
    //printf("*** fifteen_all_test ENDED\n\n");
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
