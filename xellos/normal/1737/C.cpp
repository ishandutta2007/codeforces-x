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
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		int R[3], C[3];
		int reach[4] = {0, 0, 0, 0};
		for(int k = 0; k < 3; k++) {
			cin >> R[k] >> C[k];
			reach[(R[k]&1)*2+(C[k]&1)] = 1;
		}
		int RR = (R[0]+R[1]+R[2]-(R[0]^R[1]^R[2]))/2, CC = (C[0]+C[1]+C[2]-(C[0]^C[1]^C[2]))/2;
		int on_sides = (RR == 1) + (CC == 1) + (RR == N) + (CC == N);
		int x, y;
		cin >> x >> y;
		if(on_sides <= 1)
			cout << (reach[(x&1)*2+(y&1)] ? "YES\n" : "NO\n");
		else {
			cout << ((x == RR || y == CC) ? "YES\n" : "NO\n");
		}
	}
}

// look at my code
// my code is amazing