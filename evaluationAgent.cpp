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
		StateNode* best = minimax(board)
		board->
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
		// std::vector<StateNode> list = std::vector<StateNode>();
		for(int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++){
				if (this->board->unoccupied(i,j)){
					// changes board to test
					if(isMax){
						curr->board->updateState(i,j,this->player); // undone after
					} else {
						curr->board->updateState(i,j,this->opponent); 
					} 
					StateNode* child = new StateNode(!isMax, curr->board, i, j)
					// Recursive call
					minimax_help(depth-1, !isMax, child);
					// Undoes move as to prevent confusion
					curr->board->updateState(i,j,'.'); 
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