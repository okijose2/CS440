void EvaluationAgent::minimax_help(int depth, bool isMax, StateNode* curr){
	if (depth == 0){
		//
	} else {
		std::vector<StateNode> list = std::vector<StateNode>();
		for(int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++){
				if (this->board->unoccupied(i,j)){
					StateNode* node = new StateNode(!isMax, this->board, i, j)
					list.insert(node)
				}
			}
		}

	}
}

int* EvaluationAgent::minimax(){
	StateNode* head = new StateNode(true, this->board,-1, -1);
	minimax_help(2, true, head);
}