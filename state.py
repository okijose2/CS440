DIST_MAT = [[0, 1064, 673, 1401, 277],
		[1064, 0, 958, 1934, 337],
		[673, 958, 0, 1001, 399],
		[1401, 1934, 1001, 0, 387],
		[277, 337, 399, 387, 0]]

MIN_DIST = 277

W = ["AEDCA",
	 "BEACD",
	 "BABCE",
	 "DADBD",
	 "BECBD"]

LENGTH = 5

UNIT_DIST = False

'''
Class that represents the current state of the problem.
Most importantly the progress on each of the 5 widgets,
and the current location
'''
class StateNode():
	def __init__(self, env = None):
		self.progress = [0,0,0,0,0]
		self.loc = None
		self.cost = 0
		self.parent = None
		self.heur = None

	'''
	Copies data from targ to self and makes targ the parent of self
	'''
	def copy(self, targ):
		for i in range(LENGTH):
			self.progress[i] = targ.progress[i]
		self.loc = targ.loc
		self.cost = targ.cost
		self.heur = targ.heur
		self.env = targ.env
		self.parent = targ


	'''
	Returns matrix distance between two locations given as a two character string
	'''
	def dist(self, pair):
		a = ord(pair[0]) - 0x41
		b = ord(pair[1]) - 0x41
		return DIST_MAT[a][b]

	'''
	Moves to a new location and updates the progress.
	Also clears heur value as it may change upon moving to a new node
	'''
	def move(self, dest):
		self.heur = None
		if UNIT_DIST:
			self.cost += 1
		else:
			if self.loc != None:
				self.cost += self.dist(self.loc+dest)
		self.loc = dest
		for i in range(LENGTH):
			if self.progress[i] < LENGTH:
				if W[i][self.progress[i]] == dest:
					self.progress[i] = self.progress[i] + 1

	'''
	Returns true if a completed state
	'''
	def complete(self):
		result = True
		for i in range(LENGTH):
			if self.progress[i] != LENGTH:
				result = False
		return result

	'''
	Returns a list of StateNodes "moves" that can be transitioned to
	'''
	def get_transitions(self):
		moves = []
		chars = set()
		for i in range(LENGTH):
			if(self.progress[i] < LENGTH):
				chars.add(W[i][self.progress[i]])
		for char in list(chars):
			temp = StateNode()
			temp.copy(self)
			temp.move(char)
			moves.append(temp)
		return moves

	'''
	Calculates a heuristic based on unique transitions remaining.
	It will calculate it if it is still set to None from initialization,
	otherwise 
	'''
	def heuristic(self):
		# First time of execution it actually calculates it
		if self.heur == None:
			trans = set()
			mini = 5
			for i in range(LENGTH):
				mini = min(self.progress[i],mini)
				for j in range(self.progress[i],LENGTH-1):
					trans.add(W[i][j:j+1])
			if UNIT_DIST:
				self.heur = max(5-mini,len(trans)) + self.cost
			else:
				self.heur = max(5-mini,len(trans))*MIN_DIST + self.cost
		# In future calls it references a saved value		
		return self.heur

	'''
	Returns string of the path up to this point
	'''
	def get_path(self):
		if self.loc == None:
			return ""
		base = ""
		if self.parent != None and self.parent.loc != None:
			base = self.parent.get_path()
		return base+self.loc

	'''
	Returns distance cost
	'''
	def get_cost(self):
		return self.cost


