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
		if env.visited(state.progress) == False:
			env.visit(state.progress)
			moves = state.get_transitions()
			nodes += 1
			for m in moves:
				h.heappush(m)
		if len(h.heap) == 0 :
			print("A* Failure at "+str(nodes)+" nodes expanded")
			return
		state = h.heappop()
	print(str(nodes)+" expanded to find solution")			
	return state.get_path()


if __name__ == "__main__":
	print(astar_search())
