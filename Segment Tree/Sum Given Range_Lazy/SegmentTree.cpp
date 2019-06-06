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
#define prl(x)          cout<<(x)<<" "
#define Pr(x)          cout<<(x)<<endl
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
#define N 100
#define ve vector
#define INF 1e9
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
//SGR Lazy Sum of given range
void buildTree(vi& a,vi& seg,int left,int right,int index){
    if(left == right){
        seg[index] = a[left];
        return;
    }
    int mid = left+(right-left)/2;
    buildTree(a,seg,left,mid,2*index+1);
    buildTree(a,seg,mid+1,right,2*index+2);
    seg[index] = seg[2*index+1]+seg[2*index+2];
}
void updateQuery_sumQueryLazy(vi& seg,vi& lazy,int left,int right,int from,int to,int delta,int index){
    if(left>right){
        return;
    }
    if(lazy[index]!=0){
        seg[index]+=lazy[index]*(right-left+1);
        if(left!=right){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(from>right || to<left){
        return;
    }
    if(from<=left && right<=to){
        seg[index]+=delta*(right-left+1);
        if(left!=right){
            lazy[2*index+1]+=delta;
            lazy[2*index+2]+=delta;
        }
        return;
    }
    int mid = left+(right-left)/2;
    updateQuery_sumQueryLazy(seg,lazy,left,mid,from,to,delta,2*index+1);
    updateQuery_sumQueryLazy(seg,lazy,mid+1,right,from,to,delta,2*index+2);
    seg[index]=seg[2*index+1]+seg[2*index+2];
}
int sumQueryLazy(vi& seg,vi& lazy,int left,int right,int from,int to,int index){
    if(left>right){
        return 0;
    }
    if(lazy[index]!=0){
        seg[index]+=lazy[index]*(right-left+1);
        if(left!=right){
            lazy[2*index+1]+=lazy[index];
            lazy[2*index+2]+=lazy[index];
        }
        lazy[index]=0;
    }
    if(from>right || to<left){
        return 0;
    }
    if(from<=left && to>=right){
        return seg[index];
    }
    int mid = (left+right)/2;
    return sumQueryLazy(seg,lazy,left,mid,from,to,2*index+1)+sumQueryLazy(seg,lazy,mid+1,right,from,to,2*index+2);
}
int main(){
    Inp
    vi a;
    int n,x;
    cin>>n;
    rep(i,0,n){
        cin>>x;
        a.pb(x);
    }
    int h = (int)ceil(log2(n));
    int szTree=2*(int)pow(2,h)-1;
    vi segtree(szTree,INF);
    vi lazy(szTree,0);
    buildTree(a,segtree,0,n-1,0);
    int from=4,to=5;
    int delta=5;
    updateQuery_sumQueryLazy(segtree,lazy,0,n-1,from,to,delta,0);
    from=1,to=6;
    int res = sumQueryLazy(segtree,lazy,0,n-1,from,to,0);
    cout<<res<<"\n";
return 0;
}
