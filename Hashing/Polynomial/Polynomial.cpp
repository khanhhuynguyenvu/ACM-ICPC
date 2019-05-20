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
#define N 1000005
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
ll MOD = 1e9+7;
ll f[N],mul[N];
unsigned long long polyHash(string s){
    unsigned long long hashValue = 0;
    rep(i,0,sz(s)){
        hashValue = ((hashValue*26)%MOD+(s[i]-'a'))%MOD;
        f[i+1] = hashValue;
    }
    return hashValue;
}
/* poly hashing
    65a^3+108a^2+103a^1+111a^0
*/
int T,tc=0;
int main(){
    Inp
    f[0]=0;
    mul[0] = 1;
    for (int i = 1; i < N; i++)
        mul[i] = (mul[i - 1] * 26) % MOD;
    
    int n = sz(s),l = 2;
    debug(f[l])
    debug(((f[n] - (f[n - l] * mul[l]) % MOD) + MOD) % MOD)
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        polyHash(s);
        int ans = 0,n=sz(s);
        rep(l,1,n+1){
            if(f[l] == ((f[n] - (f[n - l] * mul[l]) % MOD) + MOD) % MOD){
                ans++;
            }
        }
        cout<<"Case :"<<++tc<<" "<<ans<<"\n";
    }
return 0;
}
