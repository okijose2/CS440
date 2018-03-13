#include "ReflexAgent.h"
#include "board.h"
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

#define PLAYER_1 'a'
#define PLAYER_2 'A'

#define BOARD_SIZE 7

#define UNPLAYED '.'
#define RED_CHIP 'R'
#define BLUE_CHIP 'B'


ReflexAgent::ReflexAgent(char player, char opponent){
	player_ = player;
	opponent_ = opponent;
}

bool ReflexAgent::gameWon(Board* board){
	bool won = false;
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+4,j, this->player_) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i,j+4, this->player_) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i+4,j+4, this->player_) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i+4,j-4, this->player_) == 5){
				return true;
			}
		}
	}
	return won;
}


bool ReflexAgent::winningMove(Board* board)
{

	bool canWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, this->player_) == 4){ //winning horizontal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+4, j)){
					board->play_piece(i+4, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i-3, j, this->player_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j)){
					board->play_piece(i-4, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j+3, this->player_) == 4){ //winning vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->player_);
					return true;
				}
				else if(board->unoccupied(i, j+4)){
					board->play_piece(i, j+4, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j-3, this->player_) == 4){ //winning negative vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-4)){
					board->play_piece(i, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j+3, this->player_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->player_);
					return true;
				}
				else if(board->unoccupied(i+4, j+4)){
					board->play_piece(i+4, j+4, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j-3, this->player_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j+1) ) {
					board->play_piece(i+1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j-3, this->player_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i+4, j-4)){
					board->play_piece(i+4, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i-1, j+1)){
					board->play_piece(i-1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j+3, this->player_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j+4)){
					board->play_piece(i-4, j+4, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j-1)){
					board->play_piece(i+1, j-1, this->player_);
					return true;
				}
			}
		}
	}
	return canWin;
}


bool ReflexAgent::oppFourInRow(Board* board)
{

	bool oppCanWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, this->opponent_) == 4){ //winning horizontal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+4, j)){
					board->play_piece(i+4, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i-3, j, this->opponent_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j)){
					board->play_piece(i-4, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j+3, this->opponent_) == 4){ //winning vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->opponent_);
					return true;
				}
				else if(board->unoccupied(i, j+4)){
					board->play_piece(i, j+4, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j-3, this->opponent_) == 4){ //winning negative vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-4)){
					board->play_piece(i, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j+3, this->opponent_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->player_);
					return true;
				}
				else if(board->unoccupied(i+4, j+4)){
					board->play_piece(i+4, j+4, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j-3, this->opponent_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j+1) ) {
					board->play_piece(i+1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j-3, this->opponent_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i+4, j-4)){
					board->play_piece(i+4, j-4, this->player_);
					return true;
				}
				else if(board->unoccupied(i-1, j+1)){
					board->play_piece(i-1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j+3, this->opponent_) == 4){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-4, j+4)){
					board->play_piece(i-4, j+4, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j-1)){
					board->play_piece(i+1, j-1, this->player_);
					return true;
				}
			}
		}
	}
	return oppCanWin;
}


bool ReflexAgent::oppThreeInRow(Board* board)
{

	bool oppThree = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+2, j, this->opponent_) == 3){ //winning horizontal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+3, j)){
					board->play_piece(i+3, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i-2, j, this->opponent_) == 3){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-3, j)){
					board->play_piece(i-3, j, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j+2, this->opponent_) == 3){ //winning vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->player_);
					return true;
				}
				else if(board->unoccupied(i, j+3)){
					board->play_piece(i, j+3, this->player_);
					return true;
				}
			}
			if(searchBoard(board, i, j, i, j-2, this->opponent_) == 3){ //winning negative vertical move
				//oppCanWin = true;
				if(board->unoccupied(i, j-3)){
					board->play_piece(i, j-3, this->player_);
					return true;
				}
				else if(board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+2, j+2, this->opponent_) == 3){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->player_);
					return true;
				}
				else if(board->unoccupied(i+3, j+3)){
					board->play_piece(i+3, j+3, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-2, j-2, this->opponent_) == 3){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-3, j-3)){
					board->play_piece(i-3, j-3, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j+1) ) {
					board->play_piece(i+1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i+2, j-2, this->opponent_) == 3){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i+3, j-3)){
					board->play_piece(i+3, j-3, this->player_);
					return true;
				}
				else if(board->unoccupied(i-1, j+1)){
					board->play_piece(i-1, j+1, this->player_);
					return true;
				}
			}
			if(searchBoardDiag(board, i, j, i-2, j+2, this->opponent_) == 3){ //winning negative horizonatal move
				//oppCanWin = true;
				if(board->unoccupied(i-3, j+3)){
					board->play_piece(i-3, j+3, this->player_);
					return true;
				}
				else if(board->unoccupied(i+1, j-1)){
					board->play_piece(i+1, j-1, this->player_);
					return true;
				}
			}
		}
	}
	return oppThree;
}


bool ReflexAgent::playGame(Board* board)
{
	//check if you have winning move
	bool gameOver = false;
	if(winningMove(board)){
		printf("Made winning move\n");
		gameOver = true;
	}
	else if(oppFourInRow(board)){
		printf("Stopped opponent from winning\n");
		gameOver = false;
	}
	else if(oppThreeInRow(board)){
		printf("Stopped opponent three in a row\n");
		gameOver = false;
	}
	
	else{
		int* winningBlock = findWinningBlock(board);
		placeStone(board, winningBlock);
		delete winningBlock;
		printf("found potential winning block\n");
		gameOver = false;
	}

	return gameWon(board);

}

				//count number of your stones in that block
				//if current block score > max block score, 
				//winningbloack equals vecotr of start, end, 
				//block scroe = search board in range
				//go back and look thorugh winning block to see hwere to place the stone
				//
int* ReflexAgent::findWinningBlock(Board* board)
{
	int* block = new int[4];
 	 	
	int maxScore = 0;

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+4, j, this->opponent_) == 0){
				//printf("hit 1 %d %d\n", i, j);
				int curScore = searchBoard(board, i, j, i+4, j, this->player_);
				if(curScore > maxScore){
					//printf("hit 2 %d %d\n", i, j);
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i+4;
					block[3] = j;
					// = {i,j,i+4, j};
					//vector<int>* winningBlock = new (arr, arr+4);
					//block = winningBlock;
					//block = new std::vector<int>(arr, arr+4);
				}
			}
			if(searchBoard(board, i, j, i-4, j, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i-4, j, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i-4;
					block[3] = j;
					//block = {i, j, i-4, j};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;				
					//block = new std::vector<int>(arr, arr+4);
				}
			}
			if(searchBoard(board, i, j, i, j+4, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i, j+4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i;
					block[3] = j+4;
					//block = {i, j, i, j+4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;				
					//block = new std::vector<int>(arr, arr+4);
				}
			}
			if(searchBoard(board, i, j, i, j-4, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i;
					block[3] = j-4;
					//block = {i, j, i, j-4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;			
					//block = new std::vector<int>(arr, arr+4);
				}
			}
			if(searchBoard(board, i, j, i+4, j+4, this->opponent_) == 0){
				int curScore = searchBoardDiag(board, i, j, i+4, j+4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i+4;
					block[3] = j+4;
					//int arr[] = {i, j, i+4, j-4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;			
				}	
			}
			if(searchBoard(board, i, j, i-4, j-4, this->opponent_)==0){
				int curScore = searchBoardDiag(board, i, j, i-4, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i-4;
					block[3] = j-4;
					//int arr[] = {i,j,i-4,j-4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;
				}
			}
			if(searchBoard(board, i, j, i+4, j-4, this->opponent_) == 0){
				int curScore = searchBoardDiag(board, i, j, i+4, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i+4;
					block[3] = j-4;
					//int arr[] = {i, j, i+4, j-4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;			
				}	
			}
			if(searchBoard(board, i, j, i-4, j+4, this->opponent_)==0){
				int curScore = searchBoardDiag(board, i, j, i-4, j+4, this->player_);
				if(curScore> maxScore){
					maxScore = curScore;
					block[0] = i;
					block[1] = j;
					block[2] = i-4;
					block[3] = j+4;
					//int arr[] = {i,j,i-4,j+4};
					//vector<int> winningBlock(arr, arr+4);
					//block = winningBlock;
				}
			}	
		}
	}
	return block;
}


//keep track of current best winning bloack score

void ReflexAgent::placeStone(Board* board, int* winningBlock)
{


	int startRow = winningBlock[0]; int startCol = winningBlock[1];
	int endRow = winningBlock[2]; int endCol = winningBlock[3];

	int dRow = 0;
	int dCol = 0;
	if(startRow < endRow){
		dRow = 1;
	}
	if(startRow > endRow){
		dRow = -1;
	}
	if(startCol < endCol){
		dCol = 1;
	}
	if(startCol > endCol){
		dCol = -1;
	}

	for(int i=0; i < 5; i++){
		if(board->unoccupied(startRow, startCol)){
			board->play_piece(startRow,startCol,this->player_);
			return;	
		}	
		startRow += dRow;
		startCol += dCol;
	}
	/**
	if(startRow == endRow || startCol == endCol){
		for(int x=startRow; x<=endRow; x++){
			for(int y=startCol; y<=endCol; y+board->unoccupied(x, y)){
					board->play_piece(x,y,this->player_);
					return;		
				}
			}
		}
	}
	else{
		int diagLength = startRow - endRow;
		if(startRow > endRow){ //east diag
			if(startCol > endCol){ //southeast diag
				for(int i=0; i<diagLength; i++board->unoccupied(startRow+i, startCol+i)){
						board->play_piece(startRow+i, startCol+i, this->player_);
						return;
					}
				}
			}
			if(startCol < endCol){ //northeast
				for(int i=0; i<diagLength; i++board->unoccupied(startRow-i, startCol+i)){
						board->play_piece(startRow-i, startCol+i, this->player_);
						return;
					}			
				}
			}
		}
		else if(startRow < endRow){ //west diag
			if(startCol > endCol){ //southwest diag
				for(int i=0; i<diagLength; i++board->unoccupied(startRow-i, startCol-i)){
						board->play_piece(startRow-i, startCol-i, this->player_);
						return;
					}
				}
			}
			if(startCol < endCol){ //northwest
				for(int i=0; i<diagLength; i++board->unoccupied(startRow+i, startCol-i)){
						board->play_piece(startRow+i, startCol-i, this->player_);
						return;
					}
				}	
			}
		}
	}*/
}

char ReflexAgent::getPlayer(){
	return this->player_;
}

int ReflexAgent::searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player)
{

	if(endRow >= BOARD_SIZE || endCol >= BOARD_SIZE || endRow < 0 || endCol < 0){
		return 0;
	}

	int count = 0; 
	int dRow = 0;
	int dCol = 0;
	if(startRow < endRow){
		dRow = 1;
	}
	if(startRow > endRow){
		dRow = -1;
	}
	if(startCol < endCol){
		dCol = 1;
	}
	if(startCol > endCol){
		dCol = -1;
	}

	int dist = abs(startRow-endRow);
	if(abs(startCol-endCol) > dist){
		dist = abs(startCol-endCol);
	}

	int i = startRow;
	int j = startCol;
	for(int k=0; k <= dist; k++){
		if(((isupper(board->boardState(i,j)) && isupper(player))) || ((islower(board->boardState(i,j)) && islower(player)))){
				count += 1;
		}
		i += dRow;
		j += dCol;
	}
	return count;
}


//check if abs startx-endx = abs starty-endy
//have an offset for(offest in range)
//length of daig is startrow-endrow
//chech which direction to go->
//if going to bottom right: for(i=0l i<length run;i++) => heck startrow+i, start col+i
//check direction of run w/if else
//if top left: startrow<end row & start col > end col
//one outermost if statemen
//in then: another if=> in else antoher
//if stary<endy +. if startx < endx
//else if startx < endx
int ReflexAgent::searchBoardDiag(Board* board, int startRow, int startCol, int endRow, int endCol, int player)
{
	return searchBoard(board, startRow, startCol, endRow, endCol, player);
	/*
	if(endRow >= BOARD_SIZE || endCol >= BOARD_SIZE || endRow < 0 || endCol < 0){
		return 0;
	}
	int count = 0;
	int diagLength = startRow - endRow;
	if(startRow > endRow){ //east diag
		if(startCol > endCol){ //southeast diag
			for(int i=0; i<diagLength; i++){
				if(isupper(board->boardState(startRow+i, startCol+i)) == isupper(player) || islower(board->boardState(startRow+i, startCol+i)) == islower(player)){
					count += 1;
				}
			}
		}
		if(startCol < endCol){ //northeast
			for(int i=0; i<diagLength; i++){
				if(isupper(board->boardState(startRow-i, startCol+i)) == isupper(player) || islower(board->boardState(startRow-i, startCol+i)) == islower(player)){
					count += 1;
				}			
			}
		}
	}
	else if(startRow < endRow){ //west diag
		if(startCol > endCol){ //southwest diag
			for(int i=0; i<diagLength; i++){
				if(isupper(board->boardState(startRow-i, startCol-i)) == isupper(player) || islower(board->boardState(startRow-i, startCol-i)) == islower(player)){
					count += 1;
				}
			}
		}
		if(startCol < endCol){ //northwest
			for(int i=0; i<diagLength; i++){
				if(isupper(board->boardState(startRow+i, startCol-i)) == isupper(player) || islower(board->boardState(startRow+i, startCol-i)) == islower(player)){
					count += 1;
				}
			}	
		}
	}
	else{
		return 0;
	}

	return count;*/
}

