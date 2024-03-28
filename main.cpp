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

    cout << "EVALUATION - blank board, MAX: " << EVALUATION(position, "MAX") << endl;
    cout << "EVALUATION - blank board, MIN: " << EVALUATION(position, "MIN") << endl;
    cout << "EVALUATION - response board, MAX: " << EVALUATION(final, "MAX") << endl;
    cout << "EVALUATION - response board, MIN: " << EVALUATION(position, "MIN") << endl; // EVALUATION TESTING

    cout << "DEEP ENOUGH? - " << DEEP_ENOUGH(final, 1) << endl;
    return 0;
}
