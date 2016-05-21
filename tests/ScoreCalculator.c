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
	destination_score->tie_break_points[opp] =source_score->tie_break_points[opp];
    destination_score->tie_break_points[you] =source_score->tie_break_points[you];
}

Score* calculate_new_score(Score* current_score, int who_won){

    Score *new_score = malloc(sizeof(Score));
    //printf("New score with address %p\n", (void*)new_score);
    copy_score(new_score, current_score);
    // if (who_won == opp)
    // {
    // 	new_score->points[opp] =fifteen;
    // 	//printf("calculate_new_score opponent %p\n", (void*)new_score->points[opp]);
    // }else{    	
    // 	new_score->points[you] =fifteen;
    // 	//printf("calculate_new_score you %p\n", (void*)new_score->points[you]);
    // }
    //printf("about to return new score with address %p\n", (void*)new_score);

    //work on new_score

    int who_lost = !who_won;
    // printf("who_won %d.\n", who_won);
    // printf("who_lost %d.\n", who_lost);
    if(new_score->is_tie_break){
    	if( new_score->tie_break_points[who_won]<= 5){
			// printf("Continue, who_won had less or equal than 5 %d\n", new_score->tie_break_points[who_won]);
			new_score->tie_break_points[who_won]++;			
			// printf("now has%d\n", new_score->tie_break_points[who_won]);	
		}else{
			if(new_score->tie_break_points[who_won] + 1 - new_score->tie_break_points[who_lost] >=2){
				//newGame(whoWon, whoLost);
				printf("End of tie break; new game. who_won had %d, who_lost had %d \n", new_score->tie_break_points[who_won], new_score->tie_break_points[who_lost]);
			}else{
				printf("Continue, who_won had %d\n", new_score->tie_break_points[who_won]);
				new_score->tie_break_points[who_won]++;
				
			}
		}
    }else{
    	//who whon had AD
		if(strcmp(new_score->points[who_won], ad) == 0){
			//end of the game - opp won
			// printf("end of the game - whoWon had Ad.\n");
			//newGame(whoWon, whoLost);
		//who won had 40	
		}else if(strcmp(new_score->points[who_won], forty)==0 ){
			//they were 40 all
			if(strcmp(new_score->points[who_lost], forty)==0){
				// printf("Ad to who whon\n");
				new_score->points[who_won] =ad;

			//who lost had AD
			}else if(strcmp(new_score->points[who_lost], ad) ==0){
				// printf("40 all\n");
				new_score->points[who_won] = forty;
				new_score->points[who_lost] = forty;        
			//who lost had less than 40
			}else{
			  //end of the game        
			  // printf("end of the game - who lost had 30 or less\n");       
			  //newGame(whoWon, whoLost);
			}      
		}else if(strcmp(new_score->points[who_won], thirty)==0){
			new_score->points[who_won] =forty;
		}else if(strcmp(new_score->points[who_won], fifteen)==0){
			new_score->points[who_won]=thirty;
		}else {
			new_score->points[who_won] =fifteen;
		}
    }  


    return new_score;
}

