#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <tuple>
//#include "ReflexAgent.h"

using namespace std;

// Defined constants
#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'

class Board
{

	public:
		Board();
		char getChar(char val);
		void initGame();
		int boardState(int row, int col); //return val at coord x,y
		void printBoard();
		uint8_t getCurrPlayer(); //return current player
		void updateState(int row, int col, char update); //update char on board a->b->c
		char currPlayer;
		void setPlayer(char player);
		bool unoccupied(int row, int col); // returns if a location is occupied
		void play_piece(int row, int col, char player);

	private:
		char state[BOARD_SIZE][BOARD_SIZE]; // class var added by Luke
		char p1_progress;
		char p2_progress;

};

#endif