#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

int l[55];
void rsolve() {
  int n;
  cin >> n;
  bool good = true;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    good &= i == l[i];
  }
  if(good) {
    cout << "0\n";
    return;
  }
  good = l[1] == 1 || l[n] == n;
  if(good) {
    cout << "1\n";
    return;
  }
  good = l[1] != n || l[n] != 1;
  if(good) {
    cout << "2\n";
    return;
  }
  cout << "3\n";
}

void solve() {
  int t;
  cin >> t;
  while(t--) {
    rsolve();
  }
}

// !editcommand?
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}