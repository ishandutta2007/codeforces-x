#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int n,d[N],sz[N];VI G[N];
void dfs(int k1,int k2){
	d[k1]=d[k2]^1,++sz[d[k1]];
	for(auto j:G[k1])if(j!=k2)dfs(j,k1);
}
signed main(){
	rd(n);
	rep(i,2,n){
		int k1,k2;rd(k1),rd(k2);
		G[k1].PB(k2),G[k2].PB(k1);
	}
	dfs(1,0);
	pt(min(sz[0],sz[1])-1,'\n');
	return 0;
}