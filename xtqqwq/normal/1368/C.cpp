#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,-1,-1,-1,-1,1,1,1};
vector<pii> ans;

int main(){
	n=readint();
	for(int i=1;i<=n+1;i++){
		int x=2*i-1;
		for(int j=0;j<7;j++) ans.pb(mp(x+dir[j][0],x+dir[j][1]));
		if(i==n+1) ans.pb(mp(x+dir[7][0],x+dir[7][1]));
	}
	printf("%d\n",ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
	return 0;
}