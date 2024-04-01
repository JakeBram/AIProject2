#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "hfiles/evaluations.h"
#include "hfiles/board.h"
using namespace std;

// TODO: Create 4 full evaluation functions to feed the minimax search.

int EVALUATION(board state, string player, int METHOD){ // Implementing the given Evaluation function
    int player_id;
    int opposite_id;
    if(player == "MAX") { // Whose turn is it?
        player_id = 1;
        opposite_id = -1;
    }
    else if(player == "MIN") {
        player_id = -1;
        opposite_id = 1;
    }

    if(METHOD == 1){
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

    else if(METHOD == 2){
        return 0;
    }
    return 0;
}

void display_board(board state) {
    char positions[9];
    string this_board;
    for(int i = 0; i < 9; i++){
        if(state.positions[i] == 1){
            positions[i] = 'X';
        }
        else if(state.positions[i] == -1){
            positions[i] = 'O';
        }
        else{
            positions[i] = '_';
        }
    }
    for(int i = 0; i < 9; i++){
        cout << positions[i];
        if(i == 8){
            cout << "\n\n";
        }
        else if((i+1)%3==0){
            cout << "\n----------\n";
        }
        else {
            cout << " | ";
        }
    }
}