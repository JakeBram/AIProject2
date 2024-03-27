#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <list>
using namespace std;

// BOARD STRUCT DEFINITION
// -----------------------
struct board{
    int positions[9];
};

// FUNCTION DEFINITIONS
// -----------------------

board MINI_MAX_A_B(board state, int depth, string player, int use_thresh, int pass_thresh);
// To select an optimal move. We will loop and call this for min and max until game is won.

int* MOVEGEN(board state, string player); // - Generate all moves that could be made

bool DEEP_ENOUGH(board state, int depth); // - Has someone won? How many ply have been explored? 

int EVALUATION(board position, string player); // - Return a number that represents a the goodness of players position
// We need four EVALUATION functions. One was given in slides. We must create 3 more.

string OPPOSITE_PLAYER(string this_player);

// --------------------------------------


// MAIN
// -----

int main(){
    int EVAL_MAX = 100; 
    int EVAL_MIN = -100;
    board position;
    for(int i = 0; i < 9; i++){
        position.positions[i] = 0;
    }

    board final = MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN);
    cout << "Response Board: ";
    for (int i = 0; i < 9; i++){
        cout << final.positions[i] << ", ";
    }

    return 0;
}

// --------------------------------------

// FUNCTION IMPLEMENTATIONS
// --------------------------------------

board MINI_MAX_A_B(board state, int depth, string player, int use_thresh, int pass_thresh){ // Return the optimal move

    // Function Vars
    int VALUE;
    string BEST_PATH;
    string RESULT_SUCC;
    // ----------------

    // IMPLEMENTATION
    // --------------
    // If deep enough, return structure
        // VALUE = EVALUATION(position, player);
        // PATH = null;

    // Else, SUCCESSORS = MOVEGEN(position, player);
    int* ptr;
    ptr = MOVEGEN(state, player);
    int idx = 0;
    int possible_moves;
    possible_moves = ptr[idx];
    // For possible moves, create boards as arrays, set them to SUCCESSORS
    int read_in_test[82];
    int curr_sqaure = 0;
    board this_board;
    list<board> SUCCESSORS;
    for(int i = 1; i < (possible_moves*9)+1; i++){
        this_board.positions[curr_sqaure] = ptr[i];
        if(i % 9 == 0){
            curr_sqaure = 0;

            SUCCESSORS.push_back(this_board);
            int this_board[9] = {0,0,0,0,0,0,0,0,0};
        }
        else{
            curr_sqaure++;
        }
    }

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

    board first_child = SUCCESSORS.front();
    return first_child; 
};

int* MOVEGEN(board state, string player){

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
        if(state.positions[idx] == 0){
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
            this_board[inner_idx] = state.positions[inner_idx];
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
    if(depth == 9){
        return true;
    }

    if(state.positions[0] == state.positions[1] == state.positions[2]) { return true;} // Is the game won.
    if(state.positions[0] == state.positions[3] == state.positions[6]) { return true;}
    if(state.positions[3] == state.positions[4] == state.positions[5]) { return true;}
    if(state.positions[6] == state.positions[7] == state.positions[8]) { return true;}
    if(state.positions[1] == state.positions[4] == state.positions[7]) { return true;}
    if(state.positions[2] == state.positions[5] == state.positions[8]) { return true;}
    if(state.positions[0] == state.positions[4] == state.positions[8]) { return true;}
    if(state.positions[2] == state.positions[4] == state.positions[6]) { return true;}

    if(moves == 0){
        return true;
    }

    return false;
}

int EVALUATION(board state, string player){ // Implementing the given Evaluation function
    int VALUE = 0;
    // VALUE = WIN_PATHS_STATE - OPPONENT_WIN_PATHS; // SEE SLIDES FOR EXAMPLE
    return 0;
}