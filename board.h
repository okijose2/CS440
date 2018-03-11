#include <vector>
#include <iostream>
#include <tuple>

using std;

// Defined constants
#define PLAYER_1 1
#define PLAYER_2 2

#define BOARD_SIZE 7

#define UNPLAYED 0
#define RED_CHIP 1
#define BLUE_CHIP 2

class Board
{

	public:
		Board();
		void getChar();
		void initGame();
		int** boardState(); 
		void printBoard();
		void playPiece(int currPlayer, int x, int y);


	private:
		uint8_t state[BOARD_SIZE][BOARD_SIZE]; // class var added by Luke

}