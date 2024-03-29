#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "hfiles/board.h"
#include "hfiles/minimax.h"
#include "hfiles/deep_enough.h"
#include "hfiles/opposite_player.h"
#include "hfiles/evaluations.h"

using namespace std;

int main(){
    int EVAL_MAX = 8; // THESE DEPEND ON THE EVAL FUNCTION
    int EVAL_MIN = -8; // WE WILL USE 100 FOR NOW
    int depth = 0;
    string player = "MAX";
    board position; // BLANK BOARD STATE FOR NEW GAME
    for(int i = 0; i < 9; i++){
        position.positions[i] = 0;
    }

    while(DEEP_ENOUGH(position, depth) == false){
        position = MINI_MAX_A_B(position, depth, player, EVAL_MAX, EVAL_MIN);
        cout << player << " has played." << endl;
        for(int j = 0; j < 9; j++){
            cout << position.positions[j] << endl;
        }
        depth++;
        player = OPPOSITE_PLAYER(player);
    }
    cout << "Game Over." << endl;

    
    return 0;
}
