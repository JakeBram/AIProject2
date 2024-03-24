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

// DEEP-ENOUGH(postition, depth) - Has someone won? How many ply have been explored? 

// EVALUATION(position, player) - Return a number that represents a the goodness of players position

string OPPOSITE_PLAYER(string this_player);

// --------------------------------------

// MAIN
// -----

int main(){
    // Initialize a list to represent game board, "CURRENT POSITION"
    int EVAL_MAX = 100;
    int EVAL_MIN = -100;
    int position[9] = {0,0,0,0,0,0,0,0,0};
    MINI_MAX_A_B(position, 0, "MAX", EVAL_MAX, EVAL_MIN);
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
    cout << "Possible Moves: " << possible_moves << endl;
    // For possible moves, create boards as arrays, set them to SUCCESSORS
    for(int i = 0; i < (possible_moves*9)+1; i++){
        cout << "ptr[" << i << "]: " << ptr[i] << endl;
        if(i % 9 == 0){
            cout << "\n";
        }
    }

    // board_position example;
    // for(int i = 0; i < 9; i++){
    //     example.board[i] = 1;                
    // }
    // move_list.push_back(example);
    // cout << move_list.size();                move_list -> SUCCESSORS


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

    // TESTING: OPPOSITE PLAYER() - COMPLETE 
    // player = OPPOSITE_PLAYER(player);
    // cout << player << endl;


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