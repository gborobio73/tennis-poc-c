#include <stdio.h>
#include <time.h>
#include <string.h>

#include "MatchScore.h"
#include "Const.h"

void opponent_is_not_you(){
    int inverted_you = !you;
    int inverted_opp =!opp;
    if (opp == inverted_you && you == inverted_opp)
    {
        printf("*** opponent_is_not_you PASSED \n"); 
    }else{
        printf("*** opponent_is_not_you FAILED \n");
    }
}

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

void forty_fifteen_test(){
    //printf("*** fifteen_all_test STARTED\n");
    init_match_schore(opp);
    oponentPoint();
    yourPoint();
    oponentPoint();
    oponentPoint();

    Score* score = get_current_score();
  
    if (strcmp(score->points[opp], forty) == 0 && strcmp(score->points[you], fifteen) == 0)
    {
        printf("*** forty_fifteen_test PASSED \n"); 
    }else{
        printf("*** forty_fifteen_test FAILED \n"); 
    }
    end_match();
    //printf("*** fifteen_all_test ENDED\n\n");
}

void advantage_test(){
    //printf("*** fifteen_all_test STARTED\n");
    init_match_schore(opp);
    oponentPoint();
    yourPoint();
    oponentPoint();
    oponentPoint();
    yourPoint();
    yourPoint(); // forty all
    
    oponentPoint();
    yourPoint(); // forty all

    yourPoint();
    oponentPoint(); // forty all

    oponentPoint(); // address

    Score* score = get_current_score();
  
    if (strcmp(score->points[opp], ad) == 0 && strcmp(score->points[you], forty) == 0)
    {
        printf("*** advantage_test PASSED \n"); 
    }else{
        printf("*** advantage_test FAILED \n"); 
    }
    end_match();
    //printf("*** fifteen_all_test ENDED\n\n");
}

void tie_break_test(){
    init_match_schore(opp);

    Score* current_score = get_current_score();
    current_score->is_tie_break=true;

    yourPoint();
    oponentPoint();
    yourPoint();
    oponentPoint();
    oponentPoint();
    oponentPoint();
    yourPoint();
    yourPoint();
    yourPoint();
    oponentPoint();
    yourPoint();

    Score* score = get_current_score();

    if (score->tie_break_points[opp]== 5 && score->tie_break_points[you] ==6)
    {
        printf("*** tie_break_test PASSED \n"); 
    }else{
        printf("*** tie_break_test FAILED opp %d you %d \n", score->tie_break_points[opp], score->tie_break_points[you]); 

    }
    end_match();
}

int main(void)
{    
    printf("Running tests.\n");
    // opponent_is_not_you();
    // who_starts_serving_test();
    // opponent_point_test();
    // fifteen_all_test();
    //forty_fifteen_test();
    // advantage_test();
    tie_break_test();
    //printf("%s \n", ad);
    printf("End of tests.\n");
}
