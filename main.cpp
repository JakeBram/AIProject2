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
    int EVAL_MAX = 12000; // THESE DEPEND ON THE EVAL FUNCTION
    int EVAL_MIN = -12000; 
    int method1 = 1;
    int method2 = 1;
    string player = "MAX";

    int otherMax = 12000; // for method 2
    int otherMin = -12000;
    board position; // BLANK BOARD STATE FOR NEW GAME
    for(int i = 0; i < 9; i++){
        position.positions[i] = 0;
    }
    bool game_over = DEEP_ENOUGH(position, 0);
    while(game_over == false){
        position = MINI_MAX_A_B(position, 0, player, EVAL_MAX, EVAL_MIN, method1, method2).second;
        cout << "\n";
        display_board(position);
        player = OPPOSITE_PLAYER(player);
        game_over = DEEP_ENOUGH(position, 0);
    }

    return 0;
}
