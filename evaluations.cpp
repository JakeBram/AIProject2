#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "hfiles/evaluations.h"
#include "hfiles/board.h"
using namespace std;

int EVALUATION(board state, string player){ // Implementing the given Evaluation function
    int player_id;
    int opposite_id;
    if(player == "MAX") { // Whose turn is it?
        player_id = 1;
        opposite_id = 2;
    }
    else if(player == "MIN") {
        player_id = 2;
        opposite_id = 1;
    }

    int VALUE = 0;
    int WINNING = 0;
    int LOSING = 0;

    // Check lines the given player could still possibly get a win.
    if(state.positions[0] != opposite_id && state.positions[1] != opposite_id && state.positions[2]  != opposite_id) {WINNING++;} 
    if(state.positions[0] != opposite_id && state.positions[3] != opposite_id && state.positions[6]  != opposite_id) {WINNING++;}
    if((state.positions[3] != opposite_id) && (state.positions[4] != opposite_id) && (state.positions[5]  != opposite_id)) {WINNING++;}
    if((state.positions[6] != opposite_id) && (state.positions[7] != opposite_id) && (state.positions[8]  != opposite_id)) {WINNING++;}
    if((state.positions[1] != opposite_id) && (state.positions[4] != opposite_id) && (state.positions[7]  != opposite_id)) {WINNING++;}
    if((state.positions[2] != opposite_id) && (state.positions[5] != opposite_id) && (state.positions[8]  != opposite_id)) {WINNING++;}
    if((state.positions[0] != opposite_id) && (state.positions[4] != opposite_id) && (state.positions[8]  != opposite_id)) {WINNING++;}
    if((state.positions[2] != opposite_id) && (state.positions[4] != opposite_id) && (state.positions[6]  != opposite_id)) {WINNING++;}
    // Check lines the opposing player could still possibly get a win.
    if(state.positions[0] != player_id && (state.positions[1] != player_id) && (state.positions[2]  != player_id)) {LOSING++;} 
    if((state.positions[0] != player_id) && (state.positions[3] != player_id) && (state.positions[6]  != player_id)) {LOSING++;}
    if((state.positions[3] != player_id) && (state.positions[4] != player_id) && (state.positions[5]  != player_id)) {LOSING++;}
    if((state.positions[6] != player_id) && (state.positions[7] != player_id) && (state.positions[8]  != player_id)) {LOSING++;}
    if((state.positions[1] != player_id) && (state.positions[4] != player_id) && (state.positions[7]  != player_id)) {LOSING++;}
    if((state.positions[2] != player_id) && (state.positions[5] != player_id) && (state.positions[8]  != player_id)) {LOSING++;}
    if((state.positions[0] != player_id) && (state.positions[4] != player_id) && (state.positions[8]  != player_id)) {LOSING++;}
    if((state.positions[2] != player_id) && (state.positions[4] != player_id) && (state.positions[6]  != player_id)) {LOSING++;}

    VALUE = WINNING - LOSING; // Evaluate the state based on possible winning lines.
    return VALUE;
}

int EVAL_2(board position, string player){
    int idx = 0;
    int board_array[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board_array[i][j] = position.positions[idx];
            idx++;
        }
    }
    int VALUE = 99;
    return VALUE;
}