#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <list>
#include "hfiles/board.h"
#include "hfiles/minimax.h"
#include "hfiles/movegen.h"
using namespace std;

board MINI_MAX_A_B(board state, int depth, string player, int use_thresh, int pass_thresh){ // Return the optimal move

    // Function Vars
    int VALUE;
    string BEST_PATH;
    string RESULT_SUCC;
    // ----------------

    // IMPLEMENTATION
    // --------------
    // If deep enough, return structure
        // VALUE = EVALUATION(position, player);
        // PATH = null;

    // Else, SUCCESSORS = MOVEGEN(position, player);
    int* ptr;
    ptr = MOVEGEN(state, player);
    int idx = 0;
    int possible_moves;
    possible_moves = ptr[idx];
    // For possible moves, create boards as arrays, set them to SUCCESSORS
    int read_in_test[82];
    int curr_sqaure = 0;
    board this_board;
    list<board> SUCCESSORS;
    for(int i = 1; i < (possible_moves*9)+1; i++){
        this_board.positions[curr_sqaure] = ptr[i];
        if(i % 9 == 0){
            curr_sqaure = 0;

            SUCCESSORS.push_back(this_board);
            int this_board[9] = {0,0,0,0,0,0,0,0,0};
        }
        else{
            curr_sqaure++;
        }
    }

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

    board first_child = SUCCESSORS.front();
    return first_child; 
};