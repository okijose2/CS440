#ifndef REFLEXAGENT_H
#define REFLEXAGENT_H

#include "board.h"
#include <vector>
#include <iostream>
#include <tuple>

using namespace std;

#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'

class ReflexAgent
{

	public:
		ReflexAgent(char player, char chip);
		bool winningMove(Board* board);
		bool oppFourInRow(Board* board);
		bool oppThreeInRow(Board* board);
		bool playGame(Board* board); //true if make
		//vector<int> findWinningBlock(Board* board);
		char getPlayer();


	private:
		//bool wonGame;
		int searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player);
		//vector<int> findSequence();
		char chip_;
		int player_;
};


#endif