#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "board.h"
using namespace std;

pair<int, board> MINI_MAX_A_B(board state, int depth, string player, int use_thresh, int pass_thresh, int method1, int method2);
// To select an optimal move. We will loop and call this for min and max until game is won.

