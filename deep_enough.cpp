#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "hfiles/board.h"
#include "hfiles/deep_enough.h"

bool DEEP_ENOUGH(board state, int depth){
    int i = 0;
    int moves = 0;
    while(i < 9){
        if(state.positions[i] == 0){
            return false;
            moves++;
        }
        i++;
    }
    if(depth == 9){ // Have 9 moves been played?
        return true;
    }

    if(state.positions[0] == state.positions[1] == state.positions[2]) { return true;} // Is this a winning state?
    if(state.positions[0] == state.positions[3] == state.positions[6]) { return true;}
    if(state.positions[3] == state.positions[4] == state.positions[5]) { return true;}
    if(state.positions[6] == state.positions[7] == state.positions[8]) { return true;}
    if(state.positions[1] == state.positions[4] == state.positions[7]) { return true;}
    if(state.positions[2] == state.positions[5] == state.positions[8]) { return true;}
    if(state.positions[0] == state.positions[4] == state.positions[8]) { return true;}
    if(state.positions[2] == state.positions[4] == state.positions[6]) { return true;}

    if(moves == 0){ // Are there any moves available?
        return true;
    }

    return false; // If still here, game can continute. We are not Deep Enough.
}