#include "board.h"
#include "ReflexAgent.h"
#include "evaluationAgent.h"
#include <vector>
using namespace std;

#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'

int main()
{

	Board* myBoard = new Board();
	ReflexAgent player1 = ReflexAgent(PLAYER_1, PLAYER_2); //player1
	EvaluationAgent player2 = EvaluationAgent(PLAYER_2, PLAYER_1); //player2

	myBoard->play_piece(1,1,PLAYER_1);
	myBoard->play_piece(5,5,PLAYER_2);


	myBoard->setPlayer(player1.getPlayer());

	int count=0;
	char player = PLAYER_1;
	bool hasWon = false;
	while(!hasWon)
	{
		if(player == player1.getPlayer()){
			hasWon = player1.playGame(myBoard);
			player = PLAYER_2;
		}
		else{
			hasWon = player2.playGame(myBoard);
			player = PLAYER_1;
		}
		myBoard->printBoard();
		count++;
	}
	//printf("%d\n", count);

	//myBoard->printBoard();

	return 0;
}