// author: xay5421
// created: Sun May  2 22:48:10 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int T,n,m,x,a[N],b[N],id[N],ans[N];
priority_queue<pair<int,int> >pq;
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(m),rd(x);
		while(!pq.empty())pq.pop();
		rep(i,1,n)rd(a[i]),id[i]=i;
		rep(i,1,m)b[i]=0,pq.emplace(0,i);
		sort(id+1,id+1+n,[&](int k1,int k2){return a[k1]>a[k2];});
		rep(_,1,n){
			int i=id[_];
			int x=pq.top().second;
			pq.pop();
			ans[i]=x;
			b[x]+=a[i];
			pq.emplace(-b[x],x);
		}
		puts("YES");
		rep(i,1,n)pt(ans[i],' ');
		puts("");
	}
	return 0;
}