#include "board.h"
#include "stateNode.h"

using namespace std;

#define INFINITY 			1000000
#define NEGATIVE_INFINITY  -1000000

/**
  * Class representing both minimax and alpha-beta agents
  */
class EvaluationAgent{
public:
	EvaluationAgent(char player_in, bool isAlphaBeta_in);
	bool playGame(Board* board);
	int searchBoard(); // same as reflex agent
	int eval(Board* board); //evaluate function
	StateNode* minimax(Board* board); // returns the StateNode containing the move for optimal play
	void minimax_help(int depth, bool isMax, StateNode* curr); // recursive helper for minimax
	bool gameWon(Board* board);
	int searchBoard(Board* board, int startRow, int startCol, int endRow, int endCol, char player);

private:
	bool isAlphaBeta; // Is type minimax or alphabeta
	char player; //so the agent knows which player it is DOES NOT CHANGE
	char opponent; // Oponent's starting char DOES NOT CHANGE
};