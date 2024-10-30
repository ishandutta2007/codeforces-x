#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
	const int maxn = 131072;
	static char buf[maxn],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
	int res(0);
	char c = getchar();
	while(c < '0') c = getchar();
	while(c >= '0') {
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return res;
}

inline int fastpo(int x, int n, int mod) {
	int res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}

inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}

const int N = 300033;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, m;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int a[N], cnt[N];
map<pair<int, int>, int> mp;
int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	LL tot = 0;
	for(int i = 1; i <= n; i++) tot += a[i];
	int Q;
	cin >> Q;
	LL dec = 0;
	for(int i(1); i <= Q; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		int prv = -1;
		if(mp.count({x, y})) {
			prv = mp[{x, y}];
			dec -= min(a[prv], cnt[prv]);
		}
		
		if(z == 0) {
			if(prv != -1) {
				cnt[prv]--;
				dec += min(a[prv], cnt[prv]);
			}
			mp.erase({x, y});
		}else {
			if(prv != -1) {
				cnt[prv]--;
				dec += min(a[prv], cnt[prv]);
			}
			mp[{x, y}] = z;
			dec -= min(a[z], cnt[z]);
			cnt[z]++;
			dec += min(a[z], cnt[z]);
		}
		cout << tot - dec << endl;
	}
}