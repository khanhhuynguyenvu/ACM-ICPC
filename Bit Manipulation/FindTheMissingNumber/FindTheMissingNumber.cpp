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
int getMissingNo(int a[],int n){
    int xor_number = 1;
    int xor_array = a[0];
    for(int i = 2;i<=n+1;i++)
        xor_number = xor_number^i;
    for(int i = 1;i<n;i++)
        xor_array = xor_array ^a[i];
    return xor_number^xor_array;
}
int main(){
    //Inp
    int a[] = {1,2,3,4,6,7,8,9};
    /*
        X1 = A1^A2^A3^A4
        X2 = A1^A2^A4
        X1^X2 = (A1^A1)^(A2^A2)^(A3)^(A4^A4)
              = 0^0^A3^0
              = A3
    */
    int result = getMissingNo(a,8);
    cout<<result;

return 0;
}

