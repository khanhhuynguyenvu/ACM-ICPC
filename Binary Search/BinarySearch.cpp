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
#define N1 1e5+10
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
//Index Search
int BiSearch(int a[],int x,int n){
	int l = 0, r = n,mid = 0;
	while(l<=r){
		mid = l+(r-l)/2;
		printf("%d %d %d\n",l,mid,r);
		if(a[mid] == x){
			return mid;
		}else if(a[mid]<x){
			l = mid+1;
		}else{
			r = mid-1;
		}
	}
return -1;
}
//Floor Search
int FloorBSearch(int a[],int x,int n){
	int l = 0,r = n,mid = 0;
	if(x < a[0]){
		return -1;
	}
	while(l+1<r){
		mid = l+(r-l)/2;
		if(a[mid]>x){
			r = mid;
		}else{
			l = mid;
		}
	}
	return a[l];
}
int main(){
	//Inp
	int a[]={1,3,7,8,12,97};
	int n = sizeof(a)/sizeof(a[0]);
	int X = FloorBSearch(a,98,n);
	cout<<X<<endl;
return 0;
}
//0 1 1 2 3 5 8 13 21 34