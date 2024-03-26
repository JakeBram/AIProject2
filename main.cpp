#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <fstream>
#include <chrono>
#include <list>
using namespace std;

// FUNCTION DEFINITIONS
// -----------------------

void MINI_MAX_A_B(int position[9], int depth, string player, int use_thresh, int pass_thresh); // - AB Pruning, select optimal path.

int* MOVEGEN(int position[9], string player); // - Generate all moves that could be made

bool DEEP_ENOUGH(int postition[9], int depth); // - Has someone won? How many ply have been explored? 

// EVALUATION(position, player) - Return a number that represents a the goodness of players position

string OPPOSITE_PLAYER(string this_player);

// --------------------------------------

struct board{
    int positions[9];
};

// MAIN
// -----

int main(){
    // Initialize a list to represent game board, "CURRENT POSITION"
    int EVAL_MAX = 100;
    int EVAL_MIN = -100;
    int position[9] = {0,0,0,0,0,0,0,0,0};
    int position2[9] = {1,1,1,1,1,1,1,1,1};
    // MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN);
    cout << "Test 1: " << DEEP_ENOUGH(position, 0) << endl;
    cout << "Test 2: " << DEEP_ENOUGH(position2, 9) << endl;
    cout << "Test 3: " << DEEP_ENOUGH(position, 9) << endl;
    cout << "Test 4: " << DEEP_ENOUGH(position2, 0) << endl;
    return 0;
}

// --------------------------------------

// FUNCTION IMPLEMENTATIONS
// --------------------------------------

void MINI_MAX_A_B(int position[9], int depth, string player, int use_thresh, int pass_thresh){

    // Function Vars
    int VALUE;
    int NEW_VALUE;
    string PATH;
    string BEST_PATH;
    string RESULT_SUCC;
    // ----------------

    // IMPLEMENTATION
    // --------------
    // If deep enough, return structure
        // VALUE = EVALUATION(position, player);
        // PATH = null;

    // Else, SUCCESSORS = MOVEGEN(position, player); (IN PROGRESS)
    int* ptr;
    ptr = MOVEGEN(position, player);
    int idx = 0;
    int possible_moves;
    possible_moves = ptr[idx];
    cout << "Possible Moves: " << possible_moves << "\n" << endl;
    // For possible moves, create boards as arrays, set them to SUCCESSORS
    int read_in_test[82];
    int curr_sqaure = 0;
    board this_board;
    list<board> SUCCESSORS;
    for(int i = 1; i < (possible_moves*9)+1; i++){
        this_board.positions[curr_sqaure] = ptr[i];
        cout << "Memory[" << i << "]: " << this_board.positions[curr_sqaure] << endl;
        if(i % 9 == 0){
            curr_sqaure = 0;
            cout << "Board " << i / 9 << "\n\n";
            SUCCESSORS.push_back(this_board);
            int this_board[9] = {0,0,0,0,0,0,0,0,0};
        }
        else{
            curr_sqaure++;
        }
    }
    cout << "SUCCESSORS size: " << SUCCESSORS.size() << endl;

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

};

int* MOVEGEN(int position[9], string player){

    static int possible_moves[10]; // DETERMINE WHOSE TURN, NUM OF POSSIBLE MOVES
    int player_id = 0;
    if(player == "MAX") {
        player_id = 1;
    }
    else {
        player_id = 2;
    }
    int i = 0;

    for (int idx = 0; idx < 9; idx++){
        if(position[idx] == 0){
            possible_moves[i + 1] = idx;
            i++;
        }
    }
    possible_moves[0] = i; // STORE MOVE COUNT AND POSSIBLE MOVE IDX'S HERE

    static int possible_boards[82]; // GENERATE EACH POSSIBLE BOARD PER MOVE
    int possible_move_num = possible_moves[0];
    possible_boards[0] = possible_move_num;
    i = 1;
    int array_idx = 1;
    int this_board[9];
    int this_move;
    while(i <= possible_move_num){

        for(int inner_idx = 0; inner_idx < 9; inner_idx++){ // DUPLICATE POSITION
            this_board[inner_idx] = position[inner_idx];
        }
        this_move = possible_moves[i];
        this_board[this_move] = player_id; // PLAY POSSIBLE MOVE ON DUPLICATE BOARD

        // ADD DUPLICATE BOARD WITH MOVE TO possible_boards[]
        for(int idx = 0; idx < 9; idx++){
            possible_boards[array_idx] = this_board[idx];
            array_idx++;
        }

        i++; // WE HAVE PROCESSED ONE MOVE, NEXT
    }

    int* possible_moves_ptr = possible_boards;
    return possible_moves_ptr; 
    // Returns a POINTER. possible_moves[0] is the total num of possible moves.
    // Everything after is sqaures the player can play in.
}

string OPPOSITE_PLAYER(string this_player){
    string new_player;
    if (this_player == "MAX") {
        new_player = "MIN";
        }
    else if (this_player == "MIN") {
        new_player = "MAX";
        }
    else {
        cout << "OPPOSITE() experienced an error...";
        new_player = this_player;
    }
    return new_player;
}

bool DEEP_ENOUGH(int position[9], int depth){
    int i = 0;
    int moves = 0;
    while(i < 8){
        if(position[i] == 0){
            return false;
            moves++;
        }
        i++;
    }
    if(depth == 9){
        return true;
    }

    if(position[0] == position[1] == position[2]) { return true;} // Is the game won.
    if(position[0] == position[3] == position[6]) { return true;}
    if(position[3] == position[4] == position[5]) { return true;}
    if(position[6] == position[7] == position[8]) { return true;}
    if(position[1] == position[4] == position[7]) { return true;}
    if(position[2] == position[5] == position[8]) { return true;}
    if(position[0] == position[4] == position[8]) { return true;}
    if(position[2] == position[4] == position[6]) { return true;}

    if(moves == 0){
        return true;
    }

    return false;
}