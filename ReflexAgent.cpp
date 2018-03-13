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


bool ReflexAgent::winningMove(Board* board)
{
	bool canWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, this->player_) == 4){ //winning horizontal move
				canWin = true;
				if(i-1 > 0 && board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->player_);
				}
				else if(i+4 < BOARD_SIZE-1 && board->unoccupied(i+4, j)){
					board->play_piece(i+4, j, this->player_);
				}
			}
			if(searchBoard(board, i, j, i-3, j, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(i-4 > 0 && board->unoccupied(i-4, j)){
					board->play_piece(i-4, j, this->player_);
				}
				else if(i+1 < BOARD_SIZE && board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->player_);
				}
			}
			if(searchBoard(board, i, j, i, j+3, this->player_) == 4){ //winning vertical move
				canWin = true;
				if(j-1 > 0 && board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->player_);
				}
				else if(j+4 < BOARD_SIZE && board->unoccupied(i, j+4)){
					board->play_piece(i, j+4, this->player_);
				}
			}
			if(searchBoard(board, i, j, i, j-3, this->player_) == 4){ //winning negative vertical move
				canWin = true;
				if(j-4 > 0 && board->unoccupied(i, j-4)){
					board->play_piece(i, j-4, this->player_);
				}
				else if(j+1 < BOARD_SIZE && board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->player_);
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j+3, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(j+4 > 0 && i+4 > 0 && board->unoccupied(i+4, j+4)){
					board->play_piece(i+4, j+4, this->player_);
				}
				else if(j-1 < BOARD_SIZE && i-1<BOARD_SIZE && board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->player_);
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j-3, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j+1, this->player_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j-4, this->player_);
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j-3, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j-1, this->player_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j+4, this->player_);
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j+3, this->player_) == 4){ //winning negative horizonatal move
				canWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i-1, j+1, this->player_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i+4, j-4, this->player_);
				}
			}
		}
	}
	//printf("x %d", canWin);
	return canWin;
}


bool ReflexAgent::oppFourInRow(Board* board)
{

	bool oppCanWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+3, j, this->opponent_) == 4){ //winning horizontal move
				oppCanWin = true;
				if(i-1 > 0 && board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->opponent_);
				}
				else if(i+4 < BOARD_SIZE-1 && board->unoccupied(i+4, j)){
					board->play_piece(i+4, j, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i-3, j, this->opponent_) == 4){ //winning negative horizonatal move
				oppCanWin = true;
				if(i-4 > 0 && board->unoccupied(i-4, j)){
					board->play_piece(i-4, j, this->opponent_);
				}
				else if(i+1 < BOARD_SIZE && board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i, j+3, this->opponent_) == 4){ //winning vertical move
				oppCanWin = true;
				if(j-1 > 0 && board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->opponent_);
				}
				else if(j+4 < BOARD_SIZE && board->unoccupied(i, j+4)){
					board->play_piece(i, j+4, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i, j-3, this->opponent_) == 4){ //winning negative vertical move
				oppCanWin = true;
				if(j-4 > 0 && board->unoccupied(i, j-4)){
					board->play_piece(i, j-4, this->opponent_);
				}
				else if(j+1 < BOARD_SIZE && board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j+3, this->opponent_) == 4){ //winning negative horizonatal move
				oppCanWin = true;
				if(j+4 > 0 && i+4 > 0 && board->unoccupied(i+4, j+4)){
					board->play_piece(i+4, j+4, this->opponent_);
				}
				else if(j-1 < BOARD_SIZE && i-1<BOARD_SIZE && board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j-3, this->opponent_) == 4){ //winning negative horizonatal move
				oppCanWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j+1, this->opponent_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j-4, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i+3, j-3, this->opponent_) == 4){ //winning negative horizonatal move
				oppCanWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j-1, this->opponent_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i-4, j+4, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i-3, j+3, this->opponent_) == 4){ //winning negative horizonatal move
				oppCanWin = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i-1, j+1, this->opponent_);
				}
				else if(j-4 < BOARD_SIZE && i-4<BOARD_SIZE && board->unoccupied(i-4, j-4)){
					board->play_piece(i+4, j-4, this->opponent_);
				}
			}
		}
	}
	return oppCanWin;
}


bool ReflexAgent::oppThreeInRow(Board* board)
{

	bool threeInRow = false;

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+2, j, this->opponent_) == 3){ //winning horizontal move
				threeInRow = true;
				if(i-1 > 0 && board->unoccupied(i-1, j)){
					board->play_piece(i-1, j, this->opponent_);
				}
				else if(i+3 < BOARD_SIZE-1 && board->unoccupied(i+3, j)){
					board->play_piece(i+3, j, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i-2, j, this->opponent_) == 3){ //winning negative horizonatal move
				threeInRow = true;
				if(i-3 > 0 && board->unoccupied(i-3, j)){
					board->play_piece(i-3, j, this->opponent_);
				}
				else if(i+1 < BOARD_SIZE && board->unoccupied(i+1, j)){
					board->play_piece(i+1, j, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i, j+2, this->opponent_) == 3){ //winning vertical move
				threeInRow = true;
				if(j-1 > 0 && board->unoccupied(i, j-1)){
					board->play_piece(i, j-1, this->opponent_);
				}
				else if(j+3 < BOARD_SIZE && board->unoccupied(i, j+3)){
					board->play_piece(i, j+3, this->opponent_);
				}
			}
			if(searchBoard(board, i, j, i, j-2, this->opponent_) == 3){ //winning negative vertical move
				threeInRow = true;
				if(j-3 > 0 && board->unoccupied(i, j-3)){
					board->play_piece(i, j-3, this->opponent_);
				}
				else if(j+1 < BOARD_SIZE && board->unoccupied(i, j+1)){
					board->play_piece(i, j+1, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i+2, j+2, this->opponent_) == 3){ //winning negative horizonatal move
				threeInRow = true;
				if(j+3 > 0 && i+3 > 0 && board->unoccupied(i+3, j+3)){
					board->play_piece(i+3, j+3, this->opponent_);
				}
				else if(j-1 < BOARD_SIZE && i-1<BOARD_SIZE && board->unoccupied(i-1, j-1)){
					board->play_piece(i-1, j-1, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i-2, j-2, this->opponent_) == 3){ //winning negative horizonatal move
				threeInRow = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j+1, this->opponent_);
				}
				else if(j-3 < BOARD_SIZE && i-3<BOARD_SIZE && board->unoccupied(i-3, j-3)){
					board->play_piece(i-3, j-3, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i+2, j-2, this->opponent_) == 3){ //winning negative horizonatal move
				threeInRow = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i+1, j-1, this->opponent_);
				}
				else if(j-3 < BOARD_SIZE && i-3<BOARD_SIZE && board->unoccupied(i-3, j-3)){
					board->play_piece(i-3, j+3, this->opponent_);
				}
			}
			if(searchBoardDiag(board, i, j, i-2, j+2, this->opponent_) == 3){ //winning negative horizonatal move
				threeInRow = true;
				if(j+1 > 0 && i+1 > 0 && board->unoccupied(i+1, j+1)){
					board->play_piece(i-1, j+1, this->opponent_);
				}
				else if(j-3 < BOARD_SIZE && i-3<BOARD_SIZE && board->unoccupied(i-3, j-3)){
					board->play_piece(i+3, j-3, this->opponent_);
				}
			}
		}
	}
	return threeInRow;
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
		vector<int> winningBlock = findWinningBlock(board);
		placeStone(board, winningBlock);
		printf("found potential winning block\n");
		gameOver = false;
	}

	return gameOver;

}

				//count number of your stones in that block
				//if current block score > max block score, 
				//winningbloack equals vecotr of start, end, 
				//block scroe = search board in range
				//go back and look thorugh winning block to see hwere to place the stone
				//
vector<int> ReflexAgent::findWinningBlock(Board* board)
{
	vector<int> block;

	int maxScore = 0;

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+4, j, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i+4, j, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i,j,i+4, j};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;
				}
			}
			if(searchBoard(board, i, j, i-4, j, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i+4, j, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i, j, i-4, j};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;				
				}
			}
			if(searchBoard(board, i, j, i, j+4, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i, j+4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i, j, i, j+4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;				
				}
			}
			if(searchBoard(board, i, j, i, j-4, this->opponent_) == 0){
				int curScore = searchBoard(board, i, j, i, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i, j, i, j-4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;			
				}
			}
			/*
			if(searchBoard(board, i, j, i+4, j+4, this->opponent_) == 0){
				int curScore = searchBoardDiag(board, i, j, i+4, j+4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i, j, i+4, j-4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;			
				}	
			}
			if(searchBoard(board, i, j, i-4, j-4, this->opponent_)==0){
				int curScore = searchBoardDiag(board, i, j, i-4, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i,j,i-4,j-4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;
				}
			}
			if(searchBoard(board, i, j, i+4, j-4, this->opponent_) == 0){
				int curScore = searchBoardDiag(board, i, j, i+4, j-4, this->player_);
				if(curScore > maxScore){
					maxScore = curScore;
					int arr[] = {i, j, i+4, j-4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;			
				}	
			}
			if(searchBoard(board, i, j, i-4, j+4, this->opponent_)==0){
				int curScore = searchBoardDiag(board, i, j, i-4, j+4, this->player_);
				if(curScore> maxScore){
					maxScore = curScore;
					int arr[] = {i,j,i-4,j+4};
					vector<int> winningBlock(arr, arr+4);
					block = winningBlock;
				}
			}
			*/		
		}
	}
	for(unsigned i=0; i<block.size(); i++){
		printf("%d,", block[i]);
	}
	return block;
}


//keep track of current best winning bloack score

void ReflexAgent::placeStone(Board* board, vector<int> winningBlock)
{


	int startRow = winningBlock[0]; int startCol = winningBlock[1];
	int endRow = winningBlock[2]; int endCol = winningBlock[3];
/*
	int i = startRow; int j = startCol;
	if(startRow > endRow){
		i = endRow;
	}
	if(startCol > endCol){
		j = endCol;
	}
*/
	for(int x=startRow; x<=endRow; x++){
		for(int y=startCol; y<=endCol; y++){
			if(board->unoccupied(x, y)){
				board->play_piece(x,y,this->player_);
				break;
			}
		}
	}

}


char ReflexAgent::getPlayer(){
	return this->player_;
}

int ReflexAgent::searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player)
{
	int count = 0;
	if(endRow >= BOARD_SIZE || endCol >= BOARD_SIZE || endRow < 0 || endCol < 0){
		return 0;
	}
	//if start row& endr word != diff for loop
	for(int i=startRow; i<=endRow; i++){
		for(int j=startCol; j <=endCol; j++){
			if(((isupper(board->boardState(i,j)) && isupper(player))) || ((islower(board->boardState(i,j)) && islower(player)))){
				count += 1;
			}
		}
	}
	//printf("count = %d \n", count);
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
				if(isupper(board->boardState(startRow-i, startCol+i)) == isupper(player) || islower(board->boardState(startRow+i, startCol+i)) == islower(player)){
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

	return count;
}
