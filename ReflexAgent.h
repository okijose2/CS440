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
		ReflexAgent(char player, char opponent);
		bool winningMove(Board* board); //true if there is a winning move
		bool oppFourInRow(Board* board); //true if opponent has 4 in a row, update board state internally
		bool oppThreeInRow(Board* board); //true if opponent has three in a row, update board state internally
		bool playGame(Board* board); //true if you wan win
		vector<int> findWinningBlock(Board* board);
		void placeStone(Board* board, vector<int> winningBlock);
		char getPlayer();


	private:
		//bool wonGame;
		int searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player); //searches board for chains fo the same color/player
		//vector<int> findSequence();
		char opponent_;
		char player_;
		int searchBoardDiag(Board* board, int startRow, int startCol, int endRow, int endCol, int player);
};


#endif