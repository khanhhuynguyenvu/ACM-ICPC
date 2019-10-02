from collections import defaultdict
class Cyclic(object):
	"""docstring for Cyclic"""
	def __init__(self, n,e):
		super(Cyclic, self).__init__()
		self.vertices=n
		self.g=defaultdict(list)
		for edge in e:
			x,y=edge[0],edge[1]
			self.g[x].append(y)
	def isCylic(self):
		used=[0 for i in range(self.vertices)]
		for i in range(0,self.vertices):
			if used[i]==0:
				if self.dfs(i,used):
					return True
		return False
	def dfs(self,v,used):
		used[v]=1
		for i in self.g[v]:
			if used[i]==1:
					return True
			elif used[i]==0:
				return self.dfs(i,used)
		used[v]=2
		return False

main = Cyclic(3,[[0,1],[1,2],[2,0]])
print(main.isCylic())
		