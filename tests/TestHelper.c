#include "../src/Const.h"
#include "../src/MatchScore.h"

void make_game_for(int who_gets_the_game){
    if (who_gets_the_game == opp)
    {
        yourPoint();
        yourPoint();
        oponentPoint();
        oponentPoint();
        yourPoint();    
        oponentPoint();
        yourPoint();
        oponentPoint();
        oponentPoint();
        oponentPoint();
    }else{
        yourPoint();
        yourPoint();
        oponentPoint();
        oponentPoint();
        yourPoint();    
        oponentPoint();
        yourPoint();
        oponentPoint();
        yourPoint();
        yourPoint();
    }
}

void build_tie_break(){
    make_game_for(opp);
    make_game_for(opp);
    make_game_for(opp);

    make_game_for(you);
    make_game_for(you);
    make_game_for(you);

    make_game_for(opp);
    make_game_for(opp);
    make_game_for(you);
    make_game_for(you);

    make_game_for(opp);
    make_game_for(you);
}

void make_set_for(int who_gets_the_set){

}

