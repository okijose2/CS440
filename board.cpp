#include "board.h"
#include <vector>
#include <iostream>

using namespace std;


#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'


Board::Board(){
	initGame();
	this->p1_progress = PLAYER_1;
	this->p2_progress = PLAYER_2;
}

/**
  * Converts player value to proper char
  */
char Board::getChar(char val){
	return val++;
	/*
	if(val == RED_CHIP){
		return 'R';
	} else if (val == BLUE_CHIP) {
		return 'B';
	}
	return ' ';
	*/
}

void Board::updateState(int row, int col, char update)
{
	this->state[row][col] = update;
}

/**
  * My init method using the class variable
  */
void Board::initGame() {
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			this->state[i][j] = UNPLAYED;
		}
	}

	this->currPlayer = PLAYER_1;
}

void Board::setPlayer(char player){
	this->currPlayer = player;
}

int Board::boardState(int row, int col)
{
	int state_ = this->state[row][col];
	return state_;
}

/**
  * Prints the state of the board to the terminal 
  */
void Board::printBoard()
{
	printf("\n");
	for (int i = 0; i < BOARD_SIZE; i++){
		for (int j = 0; j < BOARD_SIZE; j++){
			printf("%c", this->state[i][j]);
		}
		printf("\n");
	}
	
}

/**
  * returns true if location is availible and valid
  */
bool Board::unoccupied(int row, int col)
{
	if(row < 0 || col < 0 || row >= BOARD_SIZE || col >= BOARD_SIZE){
		return false;
	}
	if(this->state[row][col] == '.'){
		return true;
	} else {
		return false;
	}
}

void Board::play_piece(int row, int col, char player){
	if(player == PLAYER_1){
		this->state[row][col] = p1_progress;
		p1_progress++;
	} else {
		this->state[row][col] = p2_progress;
		p2_progress++;
	}
}

void Board::unplay_piece(int row, int col, char player){
	this->state[row][col] = UNPLAYED;
	if(player == PLAYER_1){
		p1_progress--;
	} else {
		p2_progress--;
	}
}

