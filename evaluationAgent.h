#include "board.h"
#include "stateNode.h"

#define INFINITY 			1000000
#define NEGATIVE_INFINITY  -1000000

/**
  * Class representing both minimax and alpha-beta agents
  */
class EvaluationAgent{
public:
	EvaluationAgent(bool isAlphaBeta_in, char player_in);
	bool playGame(Board* board);
	int searchBoard(); // same as reflex agent
	int eval(Board* board); //evaluate function
	StateNode* minimax(Board* board); // returns the StateNode containing the move for optimal play
	StateNode* minimax_help(int depth, bool isMax, StateNode* curr); // recursive helper for minimax

private:
	bool isAlphaBeta; // Is type minimax or alphabeta
	char player; //so the agent knows which player it is DOES NOT CHANGE
	char player_progress; // does change
	char opponent; // Oponent's starting char DOES NOT CHANGE
}