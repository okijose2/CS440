#include "board.cpp"
#include "ReflexAgent.cpp"

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
	myBoard->initGame();
	//myBoard.printBoard();
	ReflexAgent player1 = ReflexAgent(PLAYER_1, RED_CHIP); //player1
	ReflexAgent player2 = ReflexAgent(PLAYER_2, BLUE_CHIP); //player2

	myBoard->updateState(1,1,PLAYER_1);
	myBoard->updateState(5,5,PLAYER_2);

	myBoard->printBoard();

	myBoard->setPlayer(player1.getPlayer());

	int count=0;
	while(player1.playGame(myBoard) || player2.playGame(myBoard) || count==10)
	{
		if(myBoard->currPlayer == player1.getPlayer()){
			player1.playGame(myBoard);
			myBoard->setPlayer(player2.getPlayer());
			myBoard->printBoard();
			count++;
		}
		else if(myBoard->currPlayer == player2.getPlayer()){
			player2.playGame(myBoard);
			myBoard->setPlayer(player1.getPlayer());
			myBoard->printBoard();
			count++;
		}
	}
	printf("%d\n", count);

	//myBoard->printBoard();

	return 0;
}