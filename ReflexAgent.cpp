#include "ReflexAgent.h"
#include <iostream>
#include <tuple>

using std;


tuple<Board, int[], int> makeMove(tuple<Board, int[], int> state)
{
	if(std::get<2>(state) == 1){
		for(int i=0; i<std::get<1>(state).size(); i++){
			if(std::get<1>(state)[i] == std::get<1>(state)[i+1]){

			}
		}
	}
	else{

	}
	
}
