from state import *
from heap import *
from environment import Environment


def astar_search():
	h = StateHeap()
	env = Environment()
	nodes = 0
	# Sets up the first set of initial positions
	state = StateNode()
	while not state.complete():
		#if env.visited(state) == False:
		#env.visit(state)
		#print("Total: "+str(state.heuristic())+", "+str(state.heuristic()-state.cost)+", "+str(state.cost))
		moves = state.get_transitions()
		nodes += 1
		for m in moves:
			h.heappush(m)
		if len(h.heap) == 0 :
			print("A* Failure at "+str(nodes)+" nodes expanded")
			return
		state = h.heappop()
	print(str(nodes)+" nodes expanded to find solution")			
	return state


if __name__ == "__main__":
	node = astar_search()
	print("Solution: "+ node.get_path())
	print("Cost: "+str(node.get_cost()))
