#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <chrono>
using namespace std;

// GLOBAL VARS
// -----------
string position;
int depth;
string player;
int use_thresh;
int pass_thresh;

int EVAL_MAX = 100;
int EVAL_MIN = -100;
int VALUE;
int NEW_VALUE;

string PATH[];
string BEST_PATH[];
string SUCCESSORS[];
string RESULT_SUCC[];

// FUNCTIONS TO BE DEFINED
// -----------------------

void MINI_MAX_A_B(string position, int depth, string player, int use_thresh, int pass_thresh); // - AB Pruning, select optimal path.

// MOVEGEN(position, player) - Generate all moves that could be made

// DEEP-ENOUGH(postition, depth) - Has someone won? How many ply have been explored? How promising is this path?

// EVALUATION(position, player) - Return a number that represents a the goodness of players position

// OPPOSITE(player) - change player turn.

int main(){
    MINI_MAX_A_B("CURRENT", 0, "MAX", EVAL_MAX, EVAL_MIN);
    return 0;
}


void MINI_MAX_A_B(string position, int depth, string player, int use_thresh, int pass_thresh){

    // If deep enough, return structure
        // VALUE = EVALUATION(position, player);
        // PATH = null;
    // Else, SUCCESSORS = MOVEGEN(position, player);

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
};