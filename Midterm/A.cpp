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
#define debug(x)       { cout << #x << " = " << x << endl; }
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
vii graph;
int n,X,Y;
bool used[N];
int dist[N];
void dfs(int id){
    used[id] = 1;
    fore(i,graph[id]){
        if(!used[*i]){
            dist[*i] = dist[id]+1;
            dfs(*i);
        }
    }
}
bool ans = 0;
void dfs_0(int id){
    if(id == X){
        ans = 1;
        return ;
    }
    if(id == 0){
        return ;
    }
    fore(i,graph[id]){
        if(dist[*i]<dist[id]){
            dfs_0(*i);
        }
    }
}
void dfs_1(int id){
    if(id == X){
        ans = 1;
        return ;
    }
    fore(i,graph[id]){
        if(dist[*i]>dist[id]){
            dfs_1(*i);
        }
    }
}
const int MAX = 100001; 
bool visit[MAX] = {0}; 
int intime[MAX]; 
int outtime[MAX]; 
int timer = 0;
void dfs_find(vii graph, int v) 
{ 
    visit[v] = true; 
    ++timer; 
    intime[v] = timer; 
  
    vector<int>::iterator it = graph[v].begin(); 
    while (it != graph[v].end()) 
    { 
        if (visit[*it]==false) 
            dfs_find(graph, *it); 
        it++; 
    } 
    ++timer; 
    outtime[v] = timer; 
} 
bool query(int u, int v) 
{ 
    return ( (intime[u]<intime[v] && outtime[u]>outtime[v]) || 
             (intime[v]<intime[u] && outtime[v]>outtime[u]) ); 
} 
int main(){
      Inp
      cin>>n;
      fill(used,0);
      fill(dist,0);
      graph.assign(n,vi());
      rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x--,y--;
        graph[x].pb(y);
        graph[y].pb(x);
      }
      dfs(0);
      dfs_find(graph,0);
      int Q;
      cin>>Q;
      while(Q--){
        ans = 0;
        int g;
        cin>>g>>X>>Y;
        X--,Y--;
        bool isSamePath = query(X,Y);
        if(!g){
            if(isSamePath && dist[X]<dist[Y]){
                ans = 1;
            }
        }else{
            if(isSamePath && dist[X]>dist[Y]){
                ans = 1;
            }
         }
        if(ans) cout<<"YES\n";
        else cout<<"NO\n";
      }
return 0;
}