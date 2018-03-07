#include "board.h"
#include <vector>
#include <iostream>
#include <priority_queue>
#include <tuple>

using std;

void initGame(int boardSize, int currPlayer)
{

	//define if board position has no stone, player1, or player2 in it
	int noStone = 0;
	int player1 = 1;  //red stone
	int player2 = 2;  //blue stone

	int boardVals[boardSize * boardSize];
	for(int i=0; i<boardSize; i++){
		for(int j=0; j<boardSize; j++){
			boardVals[boardSize*i + j] = 0;
		}
	}

	currPlayer = player1;
}


tuple<Board, boardVals, currPlayer> boardState(Board board, int[] boardVals, int currPlayer)
{
	state = make_tuple(board, boardVals, currPlayer);
	return state;
}

