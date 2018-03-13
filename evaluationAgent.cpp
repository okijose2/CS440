EvaluationAgent::EvaluationAgent(bool isAlphaBeta_in, char player_in){
	this->isAlphaBeta = isAlphaBeta_in;
	this->player = player_in;
	this->player_progress = player_in;
	if(player_in == PLAYER_1){
		this->opponent = PLAYER_2;
	} else {
		this->opponent = PLAYER_1;
	}
}

bool EvaluationAgent::playGame(Board* board){
	if(!isAlphaBeta){
		StateNode* best = minimax(board);
		board->play_piece(best->row, best->col, self->player);
	}
}

/**
  * If isMax, returns child node with max value
  * If !isMax, returns child node with min value
  */
StateNode* EvaluationAgent::minimax_help(int depth, bool isMax, StateNode* curr){
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
					} else {
						if(isMax){
							if(child->value > extreme->value){
								delete extreme;
								extreme = child;
							} else {
								delete child;
							}
						} else {
							if(child->value < extreme->value){
								delete extreme;
								extreme = child;
							} else {
								delete child;
							}
						}
					}
				}
			}
		}
		return extreme
	}
}

StateNode* EvaluationAgent::minimax(Board* board){
	StateNode* head = new StateNode(true, board,-1, -1);
	StateNode* child = minimax_help(2, true, head);
	delete head;
	return child;
}


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
}

int eval()