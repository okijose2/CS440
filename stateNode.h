#include "board.h"

#define NEGATIVE_INFINITY  -1000000
#define INFINITY  			1000000
/**
  * Node to be used in minimax/Alpha-beta tree by evaluationAgent
  * Also contains the row and column corresponding to the piece being played at that node
  *
  */
class StateNode
{
public:
	StateNode(bool isMax_in, Board* state_in);
	~StateNode();

	Board* board;
	int row; //best option
	int col; //best option
	int value;
	bool isMax;
};