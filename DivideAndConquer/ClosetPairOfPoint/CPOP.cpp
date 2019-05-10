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
#include <iomanip>
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
#define db(x)          cout<<#x<<" = "<<x<<endl;
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i < y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
#define type(itr,x) __typeof(x.begin()) itr = x.begin()
#define Inp freopen("a.inp","r",stdin);
#define Out freopen("a.out","w",stdout);
#define ve vector
#define out(x) cout<<x<<" ";
#define Otf(x) cout<<x<<endl;
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   double         inf = 1e9;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;
const   int            N   = 5e3;
// PlayGround
struct Point{
    int x,y;
};
bool cmpy(Point &a,Point &b){
    return a.y<b.y;
}
bool cmpx(Point &a,Point &b){
    return a.x<b.x;
}
double distance(Point &a,Point &b){
    double A = a.x-b.x,B = a.y-b.y;
    return sqrt(A*A+B*B);
}
double bruteForce(vector<Point> &p,int L,int R){
    double dmin = inf;
    rep(i,L,R){
        rep(j,i+1,R){
            double dist = distance(p[i],p[j]);
            dmin = dmin>dist?dist:dmin;
        }
    }
    return dmin;
}
double stripCloset(vector<Point> &p,int l,int r,double minDist){
    int mid = (l+r)/2;
    vector<Point> ar;
    rep(i,l,r){
        if(abs(p[i].x-p[mid].x)<=minDist) ar.pb(p[i]);
    }
    sort(all(ar),cmpy);
    int n = ar.size();
    double ans = minDist;
    rep(i,0,n){
        for (int j = i+1; j < n && ar[j].y-ar[i].y<minDist; j++){
            double dist = distance(ar[i],ar[j]);
            ans = ans>dist?dist:ans;
        }
    }
    return ans;
}
double Closet(vector<Point> &p,int l,int r){
    if(r-l<=3){
        return bruteForce(p,l,r);
    }
    int m = (l+r)/2;
    double left = Closet(p,l,m);
    double right = Closet(p,m+1,r);
    double mid = stripCloset(p,l,r,min(left,right));
    return mid;
}
int main(){
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL); 
    //Play
    //Inp
    int n;
    while(cin>>n,n>0){
        vector<Point> v;
        rep(i,0,n){
            Point p;
            cin>>p.x>>p.y;
            v.pb(p);
        }
        sort(all(v),cmpx);
        double ans = Closet(v,0,n);
        if(ans>=10000.0) printf("INFINITY\n");
        else printf("%.4lf\n",ans);
    }
return 0;
}