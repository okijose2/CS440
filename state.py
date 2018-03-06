DIST_MAT = [[0, 1064, 673, 1401, 277],
		[1064, 0, 958, 1934, 337],
		[673, 958, 0, 1001, 399],
		[1401, 1934, 1001, 0, 387]
		[277, 337, 399, 387, 0]]

W = ["AEDCA",
	 "BEACD",
	 "BABCE",
	 "DADBD",
	 "BECBD"]

LENGTH = 5

'''
Class that represents the current state of the problem.
Most importantly the progress on each of the 5 widgets,
and the current location
'''
Class StateNode():
	def __init__(self, loc = None):
		self.progress = [0,0,0,0,0]
		if loc != None:
			self.loc = loc
			self.progress[loc] = 1
		self.path = 0
		self.parent = None

	'''
	Copies data from targ to self and makes targ the parent of self
	'''
	def copy(self, targ):
		self.progress = targ.progress
		self.loc = targ.loc
		self.path = targ.path
		self.parent = targ

	'''
	Moves to a new location and updates the progress
	'''
	def move(self, dest):
		self.loc = dest
		self.path += 1
		for i in LENGTH:
			if self.progress[i] < LENGTH:
				if W[i][self.progress[i]]:
					self.progress[i] = self.progress[i] + 1

	'''
	Returns true if a completed state
	'''
	def completed(self):
		result = True
		for i in LENGTH:
			if self.progress[i] != LENGTH:
				result = False
		return result

	'''
	Returns matrix distance between two locations given the character
	'''
	def dist(self, c1, c2):
		a = ord(c1) - 0x41
		b = ord(c2) - 0x41
		return DIST_MAT[a][b]

	'''
	Returns a list of StateNodes "moves" that can be transitioned to
	'''
	def get_transitions(self):
		moves[]
		chars = set()
		for i in range(LENGTH):
			if(progress[i] < LENGTH):
				chars.add(W[i][progress[i]])
		for char in list(chars):
			temp = StateNode()
			temp.copy(self)
			temp.move(char)
			moves.append(temp)
		return temp




