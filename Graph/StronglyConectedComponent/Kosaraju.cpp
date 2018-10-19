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
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 1e9;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;

// PlayGround
int n,m,k=0,x,y;
vector<bool> used(N,false);
vector<int> ord,component,g[N],gr[N],g_cond;
void dfs1(int v){
    used[v] = true;
    for(int i:g[v]){
        if(!used[i]) dfs1(i);
    }
    ord.pb(v);
}
void dfs2(int v){
    used[v] = true;
    component.pb(v);
    for(int i:gr[v]){
        if(!used[i]) dfs2(i);
    }
}
int main(){
    Inp
    cin>>n>>m;
    rep(i,0,m){
        cin>>x>>y;
        --x,--y;
        g[x].pb(y);
        gr[y].pb(x);
    }
    for(int i=0;i<n;i++){
        if(!used[i]) dfs1(i);
    }
    used.assign(n,false);
    g_cond.reserve(n);
    repi(i,n-1,0){
        int v = ord[i];
        if(!used[v]){
            ++k;
            dfs2(v);
            printf("Component %d , size %d \n   vertice %d :",k,component.size(),v+1);
            for(int &j:component){
                    printf("%d ",j+1);
                    g_cond[j] = v;
            }
            printf("\n");
            component.clear();
        }
    }
return 0;
}
