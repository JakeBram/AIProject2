#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>
#include <bits/stdc++.h>
#include "hfiles/board.h"
#include "hfiles/minimax.h"
#include "hfiles/deep_enough.h"
#include "hfiles/opposite_player.h"
#include "hfiles/evaluations.h"
using namespace std;
int main(){
    clock_t start, end;
    start = clock();
    int EVAL_MAX = 12000; // THESE DEPEND ON THE EVAL FUNCTION
    int EVAL_MIN = -12000; 
    int method1 = 2;
    int method2 = 2;
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

    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
