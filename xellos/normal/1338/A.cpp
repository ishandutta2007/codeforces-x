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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		vector<cat> A(N);
		for(int i = 0; i < N; i++) cin >> A[i];
		for(int ans = 0; ans <= 50; ans++) {
			cat M = (1LL<<ans)-1;
			cat mi = A[0], mx = A[0]+M;
			bool ok = true;
			for(int i = 1; i < N; i++) {
				if(A[i]+M < mi) {
					ok = false;
					break;
				}
				mi = max(mi, A[i]);
				mx = A[i]+M;
			}
			if(!ok) continue;
			cout << ans << "\n";
			break;
		}
	}
	return 0;
}

// look at my code
// my code is amazing