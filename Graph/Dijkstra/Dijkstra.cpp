#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<functional>
using namespace std;
#define Max 105
#define ii pair<int,int>
const int INF = 1e9;
vector<vector<ii>> graph;
vector<int> dist(Max,INF);
int path[Max];

void Dijkstra(int src,vector<vector<ii>> &v,vector<int> &distance){
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	pq.push(ii(0,src));
	distance[src]=0;

	while(!pq.empty()){
		ii top = pq.top();
		pq.pop();
		int node = top.second;
		int d = top.first;
		
		for(int i = 0 ;i < v[node].size();i++){
			ii neighbor = v[node][i];
			if(d + neighbor.second < distance[neighbor.first]){
				distance[neighbor.first] = d+neighbor.second;
				pq.push(ii(distance[neighbor.first],neighbor.first));
				path[neighbor.first] = node;
			}
		}
	}
}
int main(){
	freopen("a.inp","rt",stdin);
	int n,m,s,t;
	int a,b,d;
	dist = vector<int>(Max,INF);

	cin>>n>>m>>s>>t;
	graph = vector<vector<ii>> (Max,vector<ii>());
	for(int i = 0 ; i < m;i++){
		cin>>a>>b>>d;
		graph[a].push_back(ii(b,d));
	}
	Dijkstra(s,graph,dist);
	int ans = dist[t];
	cout<<ans<<endl;

return 0;
}