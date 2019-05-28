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
vi path,res;
int search(vi a,vi b,int n,int x){
    int l = 0,r=n,pos = r;
    while(l<r){
        int mid = l+(r-l)/2;
        int id = b[mid];
        if(a[id]>x){
            pos = mid;
            r = mid;
        }else{
            l = mid+1;
        }
    }
    return pos;
}
int LIS(const vi& a){
    int len = 1;
    path.assign(sz(a),-1);
    res.assign(1,0);
    rep(i,1,sz(a)){
        if(a[i]<a[res[0]]){
            res[0]=i;
        }else if(a[i]>=a[res[len-1]]){
            path[i] = res[len-1];
            res.pb(i);
            len++;
        }else{
            int pos = search(a,res,len,a[i]);
            path[i] = res[pos-1];
            res[pos] = i;
        }
    }
    return len;
}
int main(){
    Inp
    int x,TC=0;
    while(1){
        vi ar;
        cin>>x;
        if(x!=-1) ar.pb(x);
        else return 0;
        while(cin>>x,x!=-1){
            ar.pb(x);
        }
        reverse(all(ar));
        cout<<"\n";
        if(TC>0) cout<<"\n";
        cout<<"Test #"<<++TC<<":\n";
        cout<<"  maximum possible interceptions: "<<LIS(ar)<<"\n";
    }
return 0;
}
