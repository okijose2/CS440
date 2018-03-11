#include "board.h"
#include "ReflexAgent.h"
#include <vector>

using std;

#define PLAYER_1 1
#define PLAYER_2 2

#define BOARD_SIZE 7

#define UNPLAYED 0
#define RED_CHIP 1
#define BLUE_CHIP 2

int main(int argc, char const *argv[])
{
	/* code */
	currPlayer = new ReflexAgent();
	while(game)
	{
		if(currPlayer = PLAYER_1){
			currPlayer.makeMove();
			currPlayer = PLAYER_2;
		}
		else if(currPlayer = PLAYER_2){
			currPlayer.makeMove();
			currPlayer = PLAYER_1;
		}

		if(game_over){
			break;
		}
	}
	return 0;
}