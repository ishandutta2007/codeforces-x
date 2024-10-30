#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
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
const int N=300005;
int T,n,a[N],ans[N];
vector<int>G[N];
signed main(){
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)G[i].clear(),ans[i]=1e18;
		rep(i,1,n){
			rd(a[i]);
			G[a[i]].PB(i);
		}
		rep(i,1,n)if(SZ(G[i])){
			int len=G[i][0];
			rep(j,1,SZ(G[i])-1){
				len=max(len,G[i][j]-G[i][j-1]);
			}
			len=max(len,n-G[i].back()+1);
			ans[len]=min(ans[len],i);
		}
		rep(i,2,n)ans[i]=min(ans[i],ans[i-1]);
		rep(i,1,n){
			pt(ans[i]>=1e18?-1:ans[i],' ');
		}
		puts("");
	}
	return 0;
}