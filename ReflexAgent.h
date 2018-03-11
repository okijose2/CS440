#include "board.h"
#include <vector>
#include <iostream>
#include <tuple>

using std;

#define PLAYER_1 1
#define PLAYER_2 2

#define BOARD_SIZE 7

#define UNPLAYED 0
#define RED_CHIP 1
#define BLUE_CHIP 2

class ReflexAgent
{

	public:
		void ReflexAgent(boardState, currPlayer);
		bool winningMove();
		bool oppFourInRow();
		bool oppThreeInRow();
		makeMove(board, int row, int col);
		vector<int> findWinningBlock();



	private:
		bool wonGame;
		int searchBoard(board, startRow, startCol, endRow, endCol, currPlayer);
		vector<int> findSequence();
}