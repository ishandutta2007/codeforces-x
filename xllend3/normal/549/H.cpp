/*
Date: 2015/06/06 21:15:16 Saturday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
typedef long long ll;
typedef long double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,C;
void sc(lf &x){double p;scanf("%lf",&p);x=p;}
lf a,b,c,d;
int check(lf x){
    lf Min1=min(min((a-x)*(d-x),(a-x)*(d+x)),min((a+x)*(d-x),(a+x)*(d+x)));
    lf Max1=max(max((a-x)*(d-x),(a-x)*(d+x)),max((a+x)*(d-x),(a+x)*(d+x)));
    lf Min2=min(min((b-x)*(c-x),(b-x)*(c+x)),min((b+x)*(c-x),(b+x)*(c+x)));
    lf Max2=max(max((b-x)*(c-x),(b-x)*(c+x)),max((b+x)*(c-x),(b+x)*(c+x)));
    //if(x<1e-9)printf("%lf %lf %lf %lf\n",Min1,Max1,Min2,Max2);
    if(Max1<Min2||Max2<Min1)return 0;return 1;
}
int main(){
    //ios::sync_with_stdio(false);
#ifdef LOCAL
    freopen("H.in","r",stdin);//freopen("H.out","w",stdout);
#endif
    sc(a);sc(b);sc(c);sc(d);
    lf Min=0,Max=1e30;
    rep(_,1,400){
        lf mid=(Min+Max)/2;
        if(check(mid))Max=mid;else Min=mid;
    }printf("%.15f\n",double(Min));
    return 0;
}