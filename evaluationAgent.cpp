#include "evaluationAgent.h"

EvaluationAgent::EvaluationAgent(char player_in, bool isAlphaBeta_in){
	this->isAlphaBeta = isAlphaBeta_in;
	this->player = player_in;
	if(player_in == PLAYER_1){
		this->opponent = PLAYER_2;
	} else {
		this->opponent = PLAYER_1;
	}
}

bool EvaluationAgent::playGame(Board* board){
	//move_nodes = 0;
	if(!isAlphaBeta){
		StateNode* best = minimax(board);
		printf("%d evaluated ", best->value);
		printf("%d,  %d location\n", best->row, best->col);
		printf("%d nodes expanded in this move\n", move_nodes);
		board->play_piece(best->row, best->col, player);
	}
	return gameWon(board);
}

/**
  * If isMax, returns child node with max value
  * If !isMax, returns child node with min value
  */
void EvaluationAgent::minimax_help(int depth, bool isMax, StateNode* curr) {
	if(gameWon(curr->board)){
		if(isMax){
			curr->value = -1*INFINITY;
			printf("bomb ");
		} else {
			curr->value = INFINITY;
		}
	} else if (depth == 0){
		curr->value = eval(curr->board);
	} else {
		move_nodes++;
		for(int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++){
				if (curr->board->unoccupied(i,j)){
					// changes board to test
					char currPlayer;
					if(isMax){
						currPlayer = this->player;
					} else {
						currPlayer = this->opponent; 
					} 
					curr->board->play_piece(i, j, currPlayer);
					StateNode* child = new StateNode(!isMax, curr->board);
					// Recursive call
					minimax_help(depth-1, !isMax, child);
					// Undoes move as to prevent confusion
					curr->board->unplay_piece(i, j, currPlayer);
					if(isMax){
						if(child->value > curr->value){
							//printf("sweet\n");
							curr->value = child->value;
							curr->row = i;
							curr->col = j;
						}
					} else {
						if(child->value < curr->value){
							//printf("spicy\n");
							curr->value = child->value;
							curr->row = i;
							curr->col = j;
						}
					}
					delete child;
				}
			}
		}
	}
	//printf("depth %d, value %d\n", depth, curr->value );
}

StateNode* EvaluationAgent::minimax(Board* board){
	StateNode* head = new StateNode(true, board);
	minimax_help(3, true, head);
	return head;
}

/**
StateNode* EvaluationAgent::alphabeta_helper(int depth, bool isMax, StateNode* curr, int alpha, int beta){
	StateNode* extreme = NULL; //max if max layer, min if min layer
	if (depth == 0){
		curr->value = eval(curr->board);
		return curr;
	} else {
		for(int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++){
				if (this->board->unoccupied(i,j)){
					// changes board to test
					char currPlayer;
					if(isMax){
						currPlayer = this->player;
					} else {
						currPlayer = this->opponent; 
					} 
					curr->board->play_piece(i, j, currPlayer);
					StateNode* child = new StateNode(!isMax, curr->board, i, j)
					// Recursive call
					minimax_help(depth-1, !isMax, child);
					// Undoes move as to prevent confusion
					curr->board->unplay_piece(i, j, currPlayer);
					if(extreme == NULL) {
						extreme = child;
						if(isMax){
							alpha = child->value;
						} else {
							beta = child->value;
						}
					} else {
						if(isMax){
							if(child->value > extreme->value){
								delete extreme;
								extreme = child;
								if(beta <= alpha){
									return extreme;
								}
							} else {
								delete child;
							}
						} else {
							if(child->value < extreme->value){
								delete extreme;
								extreme = child;
								if(beta <= alpha){
									return extreme;
								}
							} else {
								delete child;
							}
						}
					}
				}
			}
		}
	}
}


StateNode* EvaluationAgent::alphabeta(Board* board) {
	StateNode* head = new StateNode(true, board,-1, -1);
	StateNode* child = minimax_help(2, true, head);
	delete head;
	return child;
}**/

int EvaluationAgent::eval(Board* board){
	int internal [5]= {0,0,0,0,0};
	int opponents [5]= {0,0,0,0,0};
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			internal[searchBoard(board,i,j,i+4,j,player)]++;
			internal[searchBoard(board,i,j,i,j+4,player)]++;
			internal[searchBoard(board,i,j,i+4,j+4,player)]++;
			internal[searchBoard(board,i,j,i+4,j-4,player)]++;

			opponents[searchBoard(board,i,j,i+4,j,opponent)]++;
			opponents[searchBoard(board,i,j,i,j+4,opponent)]++;
			opponents[searchBoard(board,i,j,i+4,j+4,opponent)]++;
			opponents[searchBoard(board,i,j,i+4,j-4,opponent)]++;
		}
	}
	int sum = 0;
	for (int i = 1; i < 5; i++){
		sum += internal[i]*i*i*i;
		sum -= opponents[i]*i*i*i;
	}
	//printf("%d eval val\n", sum);
	return sum;
}

bool EvaluationAgent::gameWon(Board* board)
{
	bool won = false;
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			if(searchBoard(board, i, j, i+4,j, this->player) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i,j+4, this->player) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i+4,j+4, this->player) == 5){
				return true;
			}
			if(searchBoard(board, i, j, i+4,j-4, this->player) == 5){
				return true;
			}
		}
	}
	return won;
}


int EvaluationAgent::searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player_in)
{

	/**if(endRow >= BOARD_SIZE){
		endRow = BOARD_SIZE - 1;
	}
	if(endCol >= BOARD_SIZE){
		endCol = BOARD_SIZE - 1;
	}
	if(endCol < 0){
		endCol = 0;
	}
	if(endRow < 0){
		endRow = 0;
	}**/

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
		if(((isupper(board->boardState(i,j)) && isupper(player_in))) || ((islower(board->boardState(i,j)) && islower(player_in)))){
			count += 1;
		}
		if(((isupper(board->boardState(i,j)) && islower(player_in))) || ((islower(board->boardState(i,j)) && isupper(player_in)))){
			return 0;
		}
		i += dRow;
		j += dCol;
	}
	return count;
}