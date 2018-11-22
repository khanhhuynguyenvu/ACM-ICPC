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
#define pr(x)          cout<<x<<"\n";
#define pr1(x)         cout<<x;
#define pr2(x)         cout<<x<<" ";
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i < y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define type(itr,x) __typeof(x.begin()) itr = x.begin()
#define Inp freopen("a.inp","r",stdin);
#define Out freopen("a.out","w",stdout);
#define N 10005
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
struct Point{
    double x,y;
    bool operator <(const Point &p) const{
        return x<p.x || (x == p.x && y < p.y);
    }
};
double cross(const Point &O,const Point &A,const Point &B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> P){
    int n = P.size(),k=0;
    if(n<=3) return P;
    vector<Point> H(2*n);
    sort(P.begin(),P.end());
    rep(i,0,n){
        while(k>=2 && cross(H[k-2],H[k-1],P[i]) <=0 ) k--;
        H[k++] = P[i];
    }
    for(int i = n-1,t=k+1;i>0;--i){
        while (k>=t && cross(H[k-2],H[k-1],P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
    }
    H.resize(k-1);
    return H;
}
vector<Point> g;
int main(){
    Inp
    int T,cT=0;
    cin>>T;
    while(T--){
        int k;
        cin>>k;
        g.clear();
        while(k--){
            Point p;
            cin>>p.x>>p.y;
            g.push_back(p);
        }
        vector<Point> ans = convex_hull(g);
        cT++;
        cout<<"Case #"<<cT<<endl;
        fore(i,ans){
            Point x = *i;
            cout<<x.x<<" "<<x.y<<endl;
        }
    }
return 0;
}
//Link Problem: https://www.hackerrank.com/contests/justins-test-contest/challenges/convex-hull-1/problem
