#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <chrono>
using namespace std;

// FUNCTION DEFINITIONS
// -----------------------

void MINI_MAX_A_B(int position[9], int depth, string player, int use_thresh, int pass_thresh); // - AB Pruning, select optimal path.

int* MOVEGEN(int position[9], string player); // - Generate all moves that could be made

// DEEP-ENOUGH(postition, depth) - Has someone won? How many ply have been explored? 

// EVALUATION(position, player) - Return a number that represents a the goodness of players position

string OPPOSITE_PLAYER(string this_player);

// --------------------------------------

// MAIN
// -----

int main(){
    // Initialize a list to represent game board, "CURRENT POSITION"
    int EVAL_MAX = 100;
    int EVAL_MIN = -100;
    int position[9] = {0,0,0,0,0,0,0,0,0};
    MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN);
    return 0;
}

// --------------------------------------

// FUNCTION IMPLEMENTATIONS
// --------------------------------------

void MINI_MAX_A_B(int position[9], int depth, string player, int use_thresh, int pass_thresh){

    // Function Vars
    int VALUE;
    int NEW_VALUE;

    string PATH;
    string BEST_PATH;
    string SUCCESSORS;
    string RESULT_SUCC;
    // ----------------

    // IMPLEMENTATION
    // --------------
    // If deep enough, return structure
        // VALUE = EVALUATION(position, player);
        // PATH = null;

    // Else, SUCCESSORS = MOVEGEN(position, player); (IN PROGRESS)

    int* ptr;
    ptr = MOVEGEN(position, player);
    int idx = 0;
    int possible_moves = ptr[idx];
    idx++;
    // For possible moves, create boards as arrays, set them to SUCCESSORS

    // If SUCCESSORS.isempty(), no moves can be made, return structure as above
    // Else, for SUCC in SUCCESSORS:
        // RESULT_SUCC = MINI_MAX_A_B(SUCC, depth + 1, OPPOSITE(player), -pass_thresh, -use_thresh);
        // NEW_VALUE = -VALUE

        // If NEW_VALUE > pass_thresh:
            // pass_thresh = NEW_VALUE;
            // BEST_PATH = SUCC in front of PATH (RESULT_SUCC)

        // If pass_thresh >= use_thresh:
            // VALUE = pass_thresh;
            // PATH = BEST_PATH;

    // Return the structure
    // VALUE = pass_thresh;
    // PATH = BEST_PATH;

    // TESTING: OPPOSITE PLAYER() - COMPLETE 
    // player = OPPOSITE_PLAYER(player);
    // cout << player << endl;


};

int* MOVEGEN(int position[9], string player){
    int possible_moves[10];
    int player_id = 0;
    if(player == "MAX") {
        player_id = 1;
    }
    else {
        player_id = 2;
    }
    int i = 1;
    for (int idx = 0; idx < 9; idx++){
        if(position[idx] == -1){
            possible_moves[i + 1] = idx;
            i++;
        }
    }
    possible_moves[0] = i;
    return possible_moves; 
    // Returns a POINTER. possible_moves[0] is the total num of possible moves.
    // Everything after is sqaures the player can play in.

}

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