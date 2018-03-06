
'''
Stores T/F values over if a state has been visited
'''
class EnvNode():
	def __init__(self, val = None):
		self.value = val
		self.parent = None
		self.children = []

	def add_child(self, child):
		child.parent = self
		self.children.append(child)

	def build_layers(self, layer):
		if layer == 0:
			self.val = False
		else:
			for i in range(6):
				temp = EnvNode()
				temp.build_layers(layer-1)
				self.add_child(temp)


'''
Keeps track of visited and unvisited nodes in the Environment
'''
class Environment():
	def __init__(self):
		self.head = EnvNode()
		self.head.build_layers(5)


	'''
	Marks a position as visited
	'''
	def visit(self, state):
		node = self.head
		for i in state.positions:
			node = node.children[i]
		node.val = True

	'''
	Determines if a location has been visited
	'''
	def visited(self, state):
		node = self.head
		for i in state.positions:
			node = node.children[i]
		return node.val













