def astar_search(self, print_out = True):
	h = StateHeap("A*")
	state = self.start
	nodes = 0
	maze = self.env.getMaze()
	loc = state.visited[-1]
	maze[loc[0]][loc[1]] = len(state.visited)
	while not state.complete():
		moves = state.get_transitions()
		nodes += 1
		loc = state.visited[-1]
		for m in moves:
			loc = m.visited[-1]
			row = loc[0]
			col = loc[1]
			if maze[loc[0]][loc[1]] == 0 or maze[loc[0]][loc[1]] > len(m.visited):
				maze[loc[0]][loc[1]] = len(m.visited)
				h.heappush(m)
		if len(h.heap) == 0 :
			print("A* Failure")
			return
		state = h.heappop()			
	if print_out:
		state.print_sol(self.folder+"/11a*.txt")
		print("astar expanded "+str(nodes)+" nodes. "+str(len(state.visited)))
	return state.visited



