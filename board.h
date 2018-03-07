#include <vector>
#include <iostream>
#include <tuple>

using std;

class Board
{

	public:
		void initGame(boardSize, currPlayer);
		vector<int> boardState(board, boardVals, currPlayer); 
		void printBoard(board, boardVals);


	private:
		int boardSize = 7;
		int currPlayer;

}