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
		printf("Minimax value: %d, ", best->value);
		printf("Minimax location: %d, %d\n", best->row, best->col);
		printf("Minimax %d nodes expanded in this move\n", move_nodes);
		board->play_piece(best->row, best->col, player);
	}
	else{
		StateNode* best = alphabeta(board);
		printf("A-B value: %d, ", best->value);
		printf("A-B location: %d, %d\n", best->row, best->col);
		printf("A-B %d nodes expanded in this move\n", move_nodes);
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


void EvaluationAgent::alphabeta_helper(int depth, bool isMax, StateNode* curr, int alpha, int beta) {
	if(gameWon(curr->board)){
		if(isMax){
			curr->value = -1*INFINITY;
		} else {
			curr->value = INFINITY;
		}
	} else if (depth == 0){
		//printf("tubular 4\n");
		curr->value = eval(curr->board);
	} else {
		//printf("dope 5\n");
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
					alphabeta_helper(depth-1, !isMax, child, alpha, beta);
					// Undoes move as to prevent confusion
					curr->board->unplay_piece(i, j, currPlayer);
					if(isMax){
						int best = -1*INFINITY;
						
						if(child->value > curr->value){
							curr->value = child->value;
							curr->row = i;
							curr->col = j;
							if(curr->value > best){
								best = curr->value;
							}
							if(alpha < best){
								alpha = best;
							}
							if(beta <= alpha){
								break;
							}
						}
					} else {
						int best = INFINITY;
		
						if(child->value < curr->value){
							curr->value = child->value;
							curr->row = i;
							curr->col = j;
							if(child->value < best){
								best = child->value;
							}
							if(beta > best){
								beta = best;
							}
							if(beta <= alpha){
								break;
							}
						}
					}
					delete child;
				}
			}
		}
	}
	//printf("depth %d, value %d\n", depth, curr->value );
}

StateNode* EvaluationAgent::alphabeta(Board* board) {
	StateNode* head = new StateNode(true, board);
	alphabeta_helper(3, true, head, -1*INFINITY, INFINITY);
	return head;
}

int EvaluationAgent::eval(Board* board){
	int internal [5]= {0,0,0,0,0};
	int opponents [5]= {0,0,0,0,0};
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			internal[scanBoard(board,i,j,i+4,j,player)]++;
			internal[scanBoard(board,i,j,i,j+4,player)]++;
			internal[scanBoard(board,i,j,i+4,j+4,player)]++;
			internal[scanBoard(board,i,j,i+4,j-4,player)]++;

			opponents[scanBoard(board,i,j,i+4,j,opponent)]++;
			opponents[scanBoard(board,i,j,i,j+4,opponent)]++;
			opponents[scanBoard(board,i,j,i+4,j+4,opponent)]++;
			opponents[scanBoard(board,i,j,i+4,j-4,opponent)]++;
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
			if(scanBoard(board, i, j, i+4,j, this->player) == 5){
				return true;
			}
			if(scanBoard(board, i, j, i,j+4, this->player) == 5){
				return true;
			}
			if(scanBoard(board, i, j, i+4,j+4, this->player) == 5){
				return true;
			}
			if(scanBoard(board, i, j, i+4,j-4, this->player) == 5){
				return true;
			}
		}
	}
	return won;
}


int EvaluationAgent::scanBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player_in)
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
