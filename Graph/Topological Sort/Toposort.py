from collections import defaultdict
class TopoSort(object):
	def __init__(self, n,e):
		super(TopoSort, self).__init__()
		self.vertices=n
		self.g=defaultdict(list)
		for edge in e:
			x,y=edge[0],edge[1]
			self.g[x].append(y)
	def Sort(self):
		used={}
		res=[]
		for i in range(self.vertices):
			if i not in used:
				self.dfs(i,used,res)
		res.reverse()
		return res
	def dfs(self,v,used,res):
		used[v]=1
		for u in self.g[v]:
			if u not in used:
				self.dfs(u,used,res)
		res.append(v)

main = TopoSort(3,[[2,0],[1,2]])
print(main.Sort())
		