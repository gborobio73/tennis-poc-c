#include <stdio.h>
#include <time.h>
#include <string.h>

#include "../src/MatchScore.h"
#include "../src/Const.h"
#include "TestHelper.h"

static int best_of_sets =3;

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
    init_match_schore(opp, best_of_sets);

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
    init_match_schore(opp, best_of_sets);
    
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
    init_match_schore(opp, best_of_sets);
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
    init_match_schore(opp, best_of_sets);
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
    init_match_schore(opp, best_of_sets);
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
    init_match_schore(opp, best_of_sets);

    // Score* current_score = get_current_score();
    // current_score->is_tie_break=true;

    build_tie_break();

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

void five_four_games_test(){
    init_match_schore(you, best_of_sets);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);

    Score* score = get_current_score();
    if (score->games[opp]== 5 && score->games[you] ==4)
    {
        printf("*** five_four_games_test PASSED \n"); 
    }else{
        printf("*** five_four_games_test FAILED opp %d you %d \n", score->games[opp], score->games[you]); 

    }
    end_match();
}

void seven_six_games_test(){
    init_match_schore(you, best_of_sets);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(you); //6-6

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
    oponentPoint();
    oponentPoint();
    yourPoint();
    yourPoint();    // 8-7  

    Score* score = get_current_score();
    // printf("*** seven_six_games_test GAMES opp %d you %d \n", score->games[opp], score->games[you]);
    // printf("*** seven_six_games_test TBPOINTS opp %d you %d \n", score->tie_break_points[opp], score->tie_break_points[you]);
    if (score->games[opp]== 6 && score->games[you] ==6)
    {
        yourPoint();
        score = get_current_score();
        if (score->sets[you]== 1 )
        {
            printf("*** seven_six_games_test PASSED \n"); 
        }else{
            printf("*** seven_six_games_test FAILED sets opp %d you %d \n", score->sets[opp], score->sets[you]);
        }
        
    }else{
        printf("*** (2) seven_six_games_test FAILED games opp %d you %d \n", score->games[opp], score->games[you]); 

    }
    end_match();
}

void who_serves_test(){
    init_match_schore(you, best_of_sets);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    
    Score* score = get_current_score();
    if (score->who_serves== opp)
    {
        printf("*** who_serves_test PASSED \n"); 
    }else{
        printf("*** who_serves_test FAILED who_serves %d \n", score->who_serves); 

    }
    end_match();
}

void one_set_all_test(){
    init_match_schore(you, best_of_sets);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);

    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    
    Score* score = get_current_score();
    if (score->sets[opp] == 1 && score->sets[you]==1)
    {
        printf("*** one_set_all_test PASSED \n"); 
    }else{
        printf("*** one_set_all_test FAILED opp %d you %d \n", score->sets[opp], score->sets[you]); 

    }
    end_match();
}

void match_is_over_test(){
    init_match_schore(you, best_of_sets);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);

    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);

    make_game_for(you);
    make_game_for(you);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    make_game_for(you);
    
    Score* score = get_current_score();
    if (score->match_is_over == true)
    {
        printf("*** match_is_over_test PASSED \n"); 
    }else{
        printf("*** match_is_over_test FAILED match_is_over %s \n", score->match_is_over ? "true" : "false"); 

    }
    end_match();
}

void cancel_last_point_test(){
    init_match_schore(you, best_of_sets);
    make_game_for(you);
    make_game_for(opp);

    oponentPoint();    
    yourPoint();
    yourPoint();
    yourPoint();

    Score* previous_score = get_current_score();

    oponentPoint();
    oponentPoint();
    // printf("*** cancel_last_point_test scores %d \n", amount_of_scores()); 
    cancel_last_point();
    cancel_last_point();
    // previous_scoreintf("*** cancel_last_point_test scores %d \n", amount_of_scores()); 
    Score* score = get_current_score();

    if (score->points[opp] == previous_score->points[opp] && 
        score->points[you] == previous_score->points[you])
    {
        printf("*** cancel_last_point_test PASSED \n"); 
    }else{
        printf("*** cancel_last_point_test FAILED points opp %s you %s \n", score->points[you], previous_score->points[you]); 

    }
    end_match();
}

int main(void)
{    
    printf("Running tests.\n");
    opponent_is_not_you();
    who_starts_serving_test();
    opponent_point_test();
    fifteen_all_test();
    forty_fifteen_test();
    advantage_test();
    tie_break_test();
    five_four_games_test();
    seven_six_games_test();
    who_serves_test();
    one_set_all_test();
    match_is_over_test();
    cancel_last_point_test();
    printf("End of tests.\n");
}
