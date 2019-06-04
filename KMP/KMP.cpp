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
void KMPpreprocess(const string& p,vi& prefix){
    prefix[0]=0;
    int m = p.length();
    int j = 0;
    int i = 1;
    while(i<m){
        if(p[i]==p[j]){
            j++;
            prefix[i]=j;
            i++;
        }else{
            if(j!=0){
                j = prefix[j-1];
            }else{
                prefix[i]=0;
                i++;
            }
        }
    }
}
int KMPsearch(const string& t,const string& p,vi& prefix){
    int cnt = 0;
    int n = t.length();
    int m = p.length();
    int i =0,j=0;
    while(i<n){
        if(p[j]==t[i]){
            j++;
            i++;
        }
        if(j==m){
            //cout<<"Found pattern at: "<<(i-j)<<"\n";
            cnt++;
            j = prefix[j-1];
        }
        else if(i<n && p[j]!=t[i]){
            if(j!=0){
                j=prefix[j-1];
            }else{
                i++;
            }
        }
    }
    return cnt;
}
int main(){
    Inp
    int TC;
    cin>>TC;
    string t="",p,s;
    getline(cin,t);
    rep(g,1,TC+1){
        t="";
        getline(cin,s);
        rep(i,0,sz(s)){
            if(s[i]!=' '){
                t+=s[i];
            }
        }
       // debug(t)
        cin>>p;
        vi prefix(p.length());
        KMPpreprocess(p,prefix);
        cout<<"Case "<<g<<": "<<KMPsearch(t,p,prefix)<<"\n";
        //debug(p)
        getline(cin,t);
        
    }
return 0;
}
