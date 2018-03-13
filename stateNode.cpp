#include "stateNode.h"

StateNode::StateNode(bool isMax_in, Board* state_in){
	this->isMax = isMax_in;
	this->board = state_in;
	this->row = -1;
	this->col = -1;
	if(isMax){
		this->value = NEGATIVE_INFINITY;
	} else {
		this->value = INFINITY;
	}
}

StateNode::~StateNode(){
	
}