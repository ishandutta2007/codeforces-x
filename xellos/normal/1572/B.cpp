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
#define OVER9000 1234567890123456789LL
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
		vector<int> A(N);
		int x = 0;
		for(int i = 0; i < N; i++) {
			cin >> A[i];
			x ^= A[i];
		}
		if(x) {
			cout << "NO\n";
			continue;
		}
		vector<int> ans;
		int z = 0;
		while(z < N && A[z]) z++;
		while(z < N) {
			if(z%2 == 0) {
				for(int k = z-2; k >= 0; k -= 2) {
					ans.push_back(k);
					A[k] = A[k+1] = 0;
				}
				break;
			}
			int nz = 1;
			while(A[z+nz] == 0) nz++;
			for(int k = 0; k < nz/2; k++) {
				ans.push_back(z-1+2*k);
				A[z+2*k] = A[z+2*k+1] = 1;
			}
			if(nz%2 != 0) {
				ans.push_back(z+nz-2);
				A[z+nz-2] = A[z+nz] = 0;
				z += nz-2;
			}
			else {
				while(z < N && A[z]) z++;
			}
		}
		if(z == N) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int i = z+1; i < N-1; i++) {
			if(A[i] == 1 && A[i+1] == 1) {
				ans.push_back(i-1);
				A[i] = A[i+1] = 0;
				continue;
			}
			if(A[i] == 0) continue;
			// A[i] == 1, A[i+1] == 0, then some 1
			if(A[i+2] == 1) {
				ans.push_back(i);
				A[i] = A[i+2] = 0;
				continue;
			}
			// (0,) 1, 0, 0, ..., 1
			ans.push_back(i);
			A[i+1] = A[i+2] = 1;
			ans.push_back(i-1);
			A[i] = A[i+1] = 0;
		}
		cout << ans.size() << "\n";
		for(int i = 0; i < (int)ans.size(); i++)
			cout << ans[i]+1 << ((i+1 == (int)ans.size()) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing