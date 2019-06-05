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
#define debug(x)       { cout << #x << " = " << x << endl; }
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
struct Node{
    int val=INF;
    int lazy=0;
};
typedef vector<Node> vn;
void buildTree(vi& a,vn& st,int left,int right,int index){
    if(left == right){
        st[index].val=a[left];
        return;
    }
    int mid = left+(right-left)/2;
    buildTree(a,st,left,mid,2*index+1);
    buildTree(a,st,mid+1,right,2*index+2);
    st[index].val = st[2*index+1].val+st[2*index+2].val;
}
void payLate(vn& st,int index){
    int val = st[index].lazy;
    st[2*index+1].lazy+=val;
    st[2*index+1].val+=val;
    st[2*index+2].lazy+=val;
    st[2*index+2].val+=val;
    st[index].lazy=0;
}
void updateQuery_sumQueryLazy(vn& st,int left,int right,int from,int to,int delta,int index){
    if(left>to || right<from){
        return;
    }
    if(from<=left && right<=to){
        st[index].val+=delta;
        st[index].lazy+=delta;
        return;
    }
    payLate(st,index);
    int mid = left+(right-left)/2;
    updateQuery_sumQueryLazy(st,left,mid,from,to,delta,2*index+1);
    updateQuery_sumQueryLazy(st,mid+1,right,from,to,delta,2*index+2);
    st[index].val = st[2*index+1].val+st[2*index+2].val;
}
int sumQueryLazy(vn& st,int left,int right,int from,int to,int index){
    if(left>to || right<from){
        return 0;
    }
    if(from<=left && right<=to){
        return st[index].val;
    }
    payLate(st,index);
    int mid = left+(right-left)/2;
    return sumQueryLazy(st,left,mid,from,to,2*index+1)+sumQueryLazy(st,mid+1,right,from,to,2*index+2);
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
    //vi segtree(szTree,INF);
    //vi lazy(szTree,0);
    vn st(szTree);
    buildTree(a,st,0,n-1,0);
    debug(st[2].val);
    int from=1,to=4;
    int delta=10;
    updateQuery_sumQueryLazy(st,0,n-1,from,to,delta,0);
    from=5,to=6;
    int res = sumQueryLazy(st,0,n-1,from,to,0);
    cout<<res<<"\n";
return 0;
}
