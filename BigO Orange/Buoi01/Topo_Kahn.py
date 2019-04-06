import queue
if __name__ == '__main__':
	V,E = map(int,input().split())
	graph = [[] for i in range(V+1)]
	result = []
	for i in range(V):
		u,v = map(int,input().split())
		#graph[u].append(v)
		print(u,v)