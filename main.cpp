#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>
#include <chrono>

#include "hfiles/board.h"
#include "hfiles/minimax.h"
#include "hfiles/deep_enough.h"
#include "hfiles/opposite_player.h"
#include "hfiles/evaluations.h"

using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();
    int EVAL_MAX = 12000; // THESE DEPEND ON THE EVAL FUNCTION
    int EVAL_MIN = -12000; 
    int method1 = 2;
    int method2 = 1;
    int temp = 0;
    string player = "MAX";

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
        temp = method1;
        method1 = method2;
        method2 = temp;

        game_over = DEEP_ENOUGH(position, 0);
    }

    auto end = chrono::high_resolution_clock::now();
    double execution_time = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    cout << "Execution Time: " << execution_time << " nanoseconds.\n";

    return 0;
}
