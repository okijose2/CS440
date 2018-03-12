#include "stateNode.h"

StateNode::StateNode(bool isMax_in, Board* state_in, int row_in, int col_in){
	this->isMax = isMax_in;
	this->state = state_in;
	this->row = row_in;
	thi->col = col_in;
}