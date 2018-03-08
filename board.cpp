#include "board.h"
#include <vector>
#include <iostream>
#include <priority_queue>
#include <tuple>

using std;

/**
  * Converts player value to proper char
  */
void getChar(int val){
	if(val == RED_CHIP){
		return 'R';
	} else if (val == BLUE_CHIP) {
		return 'B';
	}
	return ' ';
}

/**
  * My init method using the class variable
  */
void initGame() {
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			state[i][j] = UNPLAYED;
		}
	}

	currPlayer = PLAYER_1;
}


int** boardState()
{
	return state;
}

/**
  * Prints the state of the board to the terminal 
  */
void printBoard(){
	for (i = 0; i < BOARD_SIZE; i++){
		for (j = 0; j < BOARD_SIZE; j++){
			printf("%s", getChar(board[i][j]));
		}
		printf("\n");
	}
}