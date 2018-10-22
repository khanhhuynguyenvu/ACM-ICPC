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
#define N 12
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
int n,m;
bool adj[N][N],dp[N][1<<N];//cell dp[j][i] checks if there is a path that visits each vertex in subset represented by mask i and ends at vertex j
bool bitmsk(){
    rep(i,0,n){
        dp[i][1<<i] = 1;
    }
    rep(i,0,1<<n){
        rep(j,0,n){
            if(i&(1<<j)){//check j-th bit is set in i
                rep(k,0,n){
                    if(i&(1<<k) //check k-th bit is set in i
                       && adj[k][j]//check edge between j and k is exits
                       && dp[k][i^(1<<j)]){//i XOR 2^j: turn off bit j-th and show the others bit 1 in i.
                        dp[j][i] = 1;//ends at vertex j, whole bitmask i visited
                        break;
                    }
                }
            }
        }
    }
    rep(i,0,n){
        if(dp[i][(1<<n)-1])
            return true;
    }
    return false;
}
int main(){
    Inp
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;//Unweight graph
        adj[y][x] = 1;
    }
    bool ans = bitmsk();
    if(ans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
return 0;
}
