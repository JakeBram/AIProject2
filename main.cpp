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
    int EVAL_MIN = -8; 

    board position; // BLANK BOARD STATE FOR NEW GAME
    for(int i = 0; i < 9; i++){
        position.positions[i] = 0;
    }

    position = MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN).second;
    for(int j = 0; j < 9; j++){
        cout << position.positions[j] << endl;
        if((j+1)%3==0){
            cout <<"\n";
        }
    }
    cout << "Game Over." << endl;

    return 0;
}
