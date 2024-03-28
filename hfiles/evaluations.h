#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <list>

#include "board.h"
using namespace std;

int EVALUATION(board position, string player); // - Return a number that represents a the goodness of players position
// We need four EVALUATION functions. One was given in slides. We must create 3 more.

int EVAL_2(board position, string player);