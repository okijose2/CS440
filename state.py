dist_mat = [[0, 1064, 673, 1401, 277],
		[1064, 0, 958, 1934, 337],
		[673, 958, 0, 1001, 399],
		[1401, 1934, 1001, 0, 387]
		[277, 337, 399, 387, 0]]

W = ["AEDCA",
	 "BEACD",
	 "BABCE",
	 "DADBD",
	 "BECBD"]

length = 5

'''
Class that represents the current state of the problem.
Most importantly the progress on each of the 5 widgets,
and the current location
'''
Class State():
	def __init__(self, loc):
		self.progress = [-1,-1,-1,-1,-1]
		self.progress[]
		self.loc = loc
		self.path = 0
		self.parent = None

	def copy(self, targ):
		self.progress = targ.progress
		self.loc = targ.loc
		self.path = targ.path
		self.parent = targ

	def move(self, dest):
		self.loc = dest
		self.path += 1
		for i in length:
			if self.progress[i] < length:
				if W[i][self.progress[i]]:
					self.progress[i] = self.progress[i] + 1

	'''
	Returns true if a completed state
	'''
	def completed(self):
		result = True
		for i in length:
			if self.progress[i] != length:
				result = False
		return result

	def dist(self, c1, c2):
		a = ord(c1) - 0x41
		b = ord(c2) - 0x41
		return dist_mat[a][b]

	def get_transitions(self):
		moves = []
		for i in range(length):
			if(progress[i] < length):


