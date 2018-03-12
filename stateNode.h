#include "board.h"


/**
  * Node to be used in minimax/Alpha-beta tree by evaluationAgent
  * Also contains the row and column corresponding to the piece being played at that node
  *
  */
class StateNode
{
public:
	StateNode(bool isMax_in, Board* state_in, int row_in, int col_in);
	~StateNode();

	Board* state;
	int row;
	int col;
	int value;
	bool isMax;
};