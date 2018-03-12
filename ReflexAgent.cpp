#include "ReflexAgent.h"
#include "board.h"
#include <iostream>
#include <tuple>

using namespace std;

#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'


ReflexAgent::ReflexAgent(char player, char chip){
	player_ = player;
	chip_ = chip;
}


bool ReflexAgent::winningMove(Board* board)
{
	bool canWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, this->player_) == 4){ //winning horizontal move
				canWin = true;
				if(i-1 > 0){
					board->updateState(i-1, j, board->getChar(this->player_));
				}
				else if(i+4 < BOARD_SIZE-1){
					board->updateState(i+4, j, board->getChar(this->player_));
				}
			}
			if(searchBoard(board, i, j, i-3, j, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(i-4 > 0){
					board->updateState(i-1, j, board->getChar(this->player_));
				}
				else if(i+1 < BOARD_SIZE){
					board->updateState(i+4, j, board->getChar(this->player_));
				}
			}
			if(searchBoard(board, i, j, i, j+3, this->player_) == 4){ //winning vertical move
				canWin = true;
				if(j-1 > 0){
					board->updateState(i, j-1, board->getChar(this->player_));
				}
				else if(j+4 < BOARD_SIZE){
					board->updateState(i, j+4, board->getChar(this->player_));
				}
			}
			if(searchBoard(board, i, j, i, j-3, this->player_) == 4){ //winning negative vertical move
				canWin = true;
				if(j-4 > 0){
					board->updateState(i, j-4, board->getChar(this->player_));
				}
				else if(j+1 < BOARD_SIZE){
					board->updateState(i, j+1, board->getChar(this->player_));
				}
			}
			/*
			if(searchBoard(board, i, j, i+3, j+3) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			if(searchBoard(board, i, j, i-3, j-3) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			*/
		}
	}
	return canWin;
}


bool ReflexAgent::oppFourInRow(Board* board)
{
	char opp = this->player_;
	if(isupper(opp)){ tolower(opp); }
	else if(islower(opp)){ toupper(opp); }

	bool oppCanWin = false;

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, opp) == 4){ //winning rightward move
				oppCanWin = true;
			}
			if(searchBoard(board, i, j, i-3, j, opp) == 4){ //winning leftward move
				oppCanWin = true;
			}
			if(searchBoard(board, i, j, i, j+3, opp) == 4){ //winning upward move
				oppCanWin = true;
			}
			if(searchBoard(board, i, j, i, j-3, opp) == 4){ //winning downward move
				oppCanWin = true;
			}
			/*
			if(searchBoard(board, i, j, i+3, j+3) == 4){ //winning negative horizonatal move
				oppCanWin = true;
			}
			if(searchBoard(board, i, j, i-3, j-3) == 4){ //winning negative horizonatal move
				oppCanWin = true;
			}
			*/
		}
	}
	return oppCanWin;
}


bool ReflexAgent::oppThreeInRow(Board* board)
{
	char opp = this->player_;
	if(isupper(opp)){ tolower(opp); }
	else if(islower(opp)){ toupper(opp); }

	bool threeInRow = false;

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, opp) == 3){ //right
				threeInRow = true;
			}
			if(searchBoard(board, i, j, i-3, j, opp) == 3){ //left
				threeInRow = true;
			}
			if(searchBoard(board, i, j, i, j+3, opp) == 3){ //up
				threeInRow = true;
			}
			if(searchBoard(board, i, j, i, j-3, opp) == 3){ //down
				threeInRow = true;
			}
			if(searchBoard(board, i, j, i+3, j+3, opp) == 3){ //winning negative horizonatal move
				threeInRow = true;
			}
			if(searchBoard(board, i, j, i-3, j-3, opp) == 3){ //winning negative horizonatal move
				threeInRow = true;
			}
		}
	}
	return threeInRow;
}


bool ReflexAgent::playGame(Board* board)
{
	int count=0;
	//check if you have winning move
	bool gameOver = false;
	if(winningMove(board)){
		gameOver = true;
	}
	else if(oppFourInRow(board)){
		count++;
	}
	else if(oppThreeInRow(board)){
		count++;
	}
	else{
		//findWinningBlock(board);
	}
	return gameOver;

}


vector< vector<int> > findWinningBlock(Board* board)
{
	char opp = this->player_;
	if(isupper(opp)){ tolower(opp); }
	else if(islower(opp)){ toupper(opp); }

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+4, j, opp) == 0){
				int starRow = i;
				int startCol = j;
				int endRow = i+4;
				int endCol = j;
			}
		}
	}
}


char ReflexAgent::getPlayer(){
	return this->player_;
}

int ReflexAgent::searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player)
{
	if(endRow >= BOARD_SIZE || endCol >= BOARD_SIZE || endRow < 0 || endCol < 0){
		return 0;
	}
	//if start row& endr word != diff for loop
	int count = 0;
	for(int i=startRow; i<=endRow; i++){
		for(int j=startCol; j <=endCol; j++){
			if((isupper(board->boardState(i,j)) && isupper(player)) || (islower(board->boardState(i,j)) && islower(player))){
				count += 1;
			}
		}
	}
	//printf("count = %d \n", count);
	return count;
}


/*
int searchBoardDiag(Board* board, int startRow, int startCol, int endRow, int endCol, int player)
{
	if(endRow >= BOARD_SIZE || endCol >= BOARD_SIZE || endRow < 0 || endCol < 0){
		return 0;
	}
	int count = 0;
	for(int i=startRow; i<=endRow; i++){
		for(int i=startCol; i <=endCol; i++){
			if(board.boardState(i,j) == player){
				count +=1;
			}
		}
	}
	return count;
}
*/


/*

			for(int inc=0; inc<4; inc++){
				if(board.boardState(row+inc, col) == board.currPlayer){
					board.boardState(row-1, col) == currPlayer;
				}	
				if(board.boardState(row-inc, col) == board.currPlayer){
					board.boardState(row+1, col) == currPlayer;
				}
				if(board.boardState(row, col+inc) == board.currPlayer){
					board.boardState(row, col-1) == currPlayer;
				}	
				if(board.boardState(row, col+inc) == board.currPlayer){
					board.boardState(row, col+1) == currPlayer;
				}
				if(board.boardState(row+inc, col+inc) == board.currPlayer){
					board.boardState(row-1, col-1) == currPlayer;
				}	
				if(board.boardState(row-inc, col-inc) == board.currPlayer){
					board.boardState(row+1, col+1) == currPlayer;
				}
			}

*/