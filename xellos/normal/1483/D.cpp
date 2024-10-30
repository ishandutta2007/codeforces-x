// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M, Q;
	cin >> N >> M;
	vector< vector<int> > E(N, vector<int>(N, 0));
	for(int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		E[u-1][v-1] = E[v-1][u-1] = w;
	}
	vector< vector<int> > D(N, vector<int>(N, 1000000001));
	for(int i = 0; i < N; i++) D[i][i] = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(E[i][j]) D[i][j] = E[i][j];
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
			if(D[i][j] > D[k][i]+D[k][j]) D[i][j] = D[j][i] = D[k][i]+D[k][j];
	vector< vector<int> > V(N, vector<int>(N, 0));
	cin >> Q;
	for(int i = 0; i < Q; i++) {
		int u, v, l;
		cin >> u >> v >> l;
		u--, v--;
		V[u][v] = V[v][u] = l;
	}
	for(int k = 0; k < N; k++)
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
			if(V[i][j]-D[k][j] > V[k][i]) V[k][i] = V[i][k] = V[i][j]-D[k][j];
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++)
		ans += (E[i][j] && E[i][j] <= V[i][j]);
	cout << ans << "\n";
}

// look at my code
// my code is amazing