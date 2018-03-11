#include "ReflexAgent.h"
#include "board.h"
#include <iostream>
#include <tuple>

using std;


bool winningMove(Board* board)
{
	bool canWin = false;
	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(i, j, i+3, j, board.currPlayer) == 4){ //winning horizontal move
				canWin = true;
			}
			if(searchBoard(i, j, i-3, j, board.currPlayer) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			if(searchBoard(i, j, i, j+3, board.currPlayer) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			if(searchBoard(i, j, i, j-3, board.currPlayer) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			if(searchBoard(i, j, i+3, j+3, board.currPlayer) == 4){ //winning negative horizonatal move
				canWin = true;
			}
			if(searchBoard(i, j, i-3, j-3, board.currPlayer) == 4){ //winning negative horizonatal move
				canWin = true;
			}
		}
	}
	return canWin;
}


bool oppFourInRow(Board* board)
{
	bool oppCanWin = false;
	if(board.currPlayer == PLAYER_1){ board.currPlayer = PLAYER_2}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(i, j, i+3, j, board.currPlayer) == 4){ //winning rightward move
				oppCanWin = true;
			}
			if(searchBoard(i, j, i-3, j, board.currPlayer) == 4){ //winning leftward move
				oppCanWin = true;
			}
			if(searchBoard(i, j, i, j+3, board.currPlayer) == 4){ //winning upward move
				oppCanWin = true;
			}
			if(searchBoard(i, j, i, j-3, board.currPlayer) == 4){ //winning downward move
				oppCanWin = true;
			}
			if(searchBoard(i, j, i+3, j+3, board.currPlayer) == 4){ //winning negative horizonatal move
				oppCanWin = true;
			}
			if(searchBoard(i, j, i-3, j-3, board.currPlayer) == 4){ //winning negative horizonatal move
				oppCanWin = true;
			}
		}
	}
	return oppCanWin;
}


bool oppThreeInRow(Board* board)
{
	bool threeInRow = false;
	if(board.currPlayer == PLAYER_1){ board.currPlayer = PLAYER_2}

	for(int i=0; i<BOARD_SIZE; i++){
		for(int j=0; j<BOARD_SIZE; j++){
			if(searchBoard(i, j, i+3, j, board.currPlayer) == 3){ //right
				threeInRow = true;
			}
			if(searchBoard(i, j, i-3, j, board.currPlayer) == 3){ //left
				threeInRow = true;
			}
			if(searchBoard(i, j, i, j+3, board.currPlayer) == 3){ //up
				threeInRow = true;
			}
			if(searchBoard(i, j, i, j-3, board.currPlayer) == 3){ //down
				threeInRow = true;
			}
			if(searchBoard(i, j, i+3, j+3, board.currPlayer) == 3){ //winning negative horizonatal move
				threeInRow = true;
			}
			if(searchBoard(i, j, i-3, j-3, board.currPlayer) == 3){ //winning negative horizonatal move
				threeInRow = true;
			}
		}
	}
	return threeInRow;
}


Board* makeMove(Board* board, int row, int col)
{

	//check if you have winning move
	if(winningMove(board)){
		board.boardState(row, col) == board.currPlayer;
	}
	else if(oppFourInRow(board)){
		board.boardState(row, col) == board.currPlayer;
	}
	else if(oppThreeInRow(board)){
		board.boardState(row, col) == board.currPlayer;
	}
	else{
		findWinningBlock(board);
	}

}


int searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, int player)
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
*?


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