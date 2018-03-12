#include "stateNode.h"
#include "<vector>"

/**
  * Class representing both minimax and alpha-beta agents
  */
class EvaluationAgent{
public:
	EvaluationAgent(char player);
	void makeMove();
	int searchBoard(); // same as reflex agent
	int eval(); //evaluate function
	int* minimax(); // returns the x,y needed for 
	void minimax_help(int depth, bool isMax, StateNode* curr); // recursive helper for minimax

private:
	bool isAlphaBeta; // Is type minimax or alphabeta
	char player; //so the agent knows which player it is
}