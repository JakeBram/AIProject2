#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <list>

#include "hfiles/board.h"
#include "hfiles/minimax.h"
#include "hfiles/deep_enough.h"

using namespace std;

int EVALUATION(board position, string player); // - Return a number that represents a the goodness of players position
// We need four EVALUATION functions. One was given in slides. We must create 3 more.

string OPPOSITE_PLAYER(string this_player);

// MAIN
// -----

int main(){
    int EVAL_MAX = 100; // THESE DEPEND ON THE EVAL FUNCTION
    int EVAL_MIN = -100; // WE WILL USE 100 FOR NOW
    board position; // BLANK BOARD STATE FOR NEW GAME
    for(int i = 0; i < 9; i++){
        position.positions[i] = 0;
    }

    board final = MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN);
    // cout << "Response Board: "; //
    // for (int i = 0; i < 9; i++){
       // cout << final.positions[i] << ", ";
    // } // TEST RESPONSE FROM MINI_MAX_A_B

    // cout << "EVALUATION - blank board, MAX: " << EVALUATION(position, "MAX") << endl;
    // cout << "EVALUATION - blank board, MIN: " << EVALUATION(position, "MIN") << endl;
    // cout << "EVALUATION - response board, MAX: " << EVALUATION(final, "MAX") << endl;
    // cout << "EVALUATION - response board, MIN: " << EVALUATION(position, "MIN") << endl; // EVALUATION TESTING

    cout << "DEEP ENOUGH? - " << DEEP_ENOUGH(final, 1) << endl;
    return 0;
}

// --------------------------------------

// FUNCTION IMPLEMENTATIONS
// --------------------------------------

string OPPOSITE_PLAYER(string this_player){
    string new_player;
    if (this_player == "MAX") {
        new_player = "MIN";
        }
    else if (this_player == "MIN") {
        new_player = "MAX";
        }
    else {
        cout << "OPPOSITE() experienced an error...";
        new_player = this_player;
    }
    return new_player;
}

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