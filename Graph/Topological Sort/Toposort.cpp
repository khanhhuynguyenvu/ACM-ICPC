#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;

#define mp             make_pair
#define pb             push_back
#define fs             first
#define sc             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(x))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i < y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define type(itr,x) __typeof(x.begin()) itr = x.begin()
#define Inp freopen("a.inp","r",stdin);
#define Out freopen("a.out","w",stdout);
#define N 100005
#define ve vector
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<vi>     vii;
typedef vector<iii>    viii;
const   int            inf = 1e9;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

// PlayGround
int V,E;
bool topo_sort(vii &graph,vi &result){
    vi indegree(V,0);
    priority_queue<int,std::vector<int>, std::greater<int>> zero_degree;
    for(int u = 0 ;u<V;u++){
        vector<int>::iterator it;
        for(it = graph[u].begin();it!=graph[u].end();it++){
            indegree[*it]++;
        }
    }
    for(int i = 0 ; i<V;i++){
        if(indegree[i] == 0){
            zero_degree.push(i);
        }
    }
    while(!zero_degree.empty()){
        int u = zero_degree.top();
        zero_degree.pop();
        result.pb(u);
        vector<int>::iterator it;
        for(it = graph[u].begin();it!=graph[u].end();it++){
            indegree[*it]--;
            if(indegree[*it] == 0){
                zero_degree.push(*it);
            }
        }
    }
    for(int i = 0 ; i < V;i++){
        if(indegree[i]!=0)
            return false;
    }
return true;
}
int main(){
    Inp
    vii graph;
    vi result;
    cin>>V>>E;
    graph.assign(V,vi());
    for(int u,v,i=0;i<E;i++){
        cin>>u>>v;
        u--,v--;
        graph[u].pb(v);
    }
    cout<<"Topo sort of graph:\n";
    if(topo_sort(graph,result)){
        for(int i=0;i<sz(result);i++){
            cout<<result[i]+1<<" ";
        }
    }
return 0;
}
