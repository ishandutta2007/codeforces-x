#include<set>
#include<map>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int n,ans;char s[1000005];
signed main(){
	rd(n);
	scanf("%s",s+1);
	int x=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='(')++x;else --x;
		if(x<0||s[i]=='('&&x==0)++ans;
	}
	if(x)puts("-1");
	else pt(ans,'\n');
	return 0;
}