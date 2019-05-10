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
void permuation(string s,int l,int r){
    if(l==r){
        cout<<s<<endl;
    }else{
        rep(i,l,r){
            swap(s[l],s[i]);
            permuation(s,l+1,r);
            swap(s[l],s[i]);
        }
    }
}
bool shouldSwap(string s,int l,int r){
    rep(i,l,r){
        if(s[i] == s[r]) return false;
    }
    return true;
}
void permuation_distinct(string s,int l,int r){
    if(l==r){
        cout<<s<<endl;
    }else{
        rep(i,l,r){
            if(shouldSwap(s,l,i)){
                swap(s[l],s[i]);
                permuation_distinct(s,l+1,r);
                swap(s[l],s[i]);
            }
        }
    }
}
int main(){
    //Inp
    string s = "abcad";
    permuation_distinct(s,0,sz(s));
return 0;
}
