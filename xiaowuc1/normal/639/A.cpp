#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// DID YOU FIX GLOBAL STATE

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
const double PI = 2 * acos(0);
const int MOD = 1000000007;
const int HASH = 3137;

int l[150005];

void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  int qq;
  scanf("%d", &qq);
  set<int> s;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &l[i]);
  }
  while(qq--) {
    int t;
    scanf("%d", &t);
    int id;
    scanf("%d", &id);
    if(t == 2) {
      if(s.count(l[id])) printf("YES\n");
      else printf("NO\n");
    }
    else {
      s.insert(l[id]);
      while(s.size() > k) s.erase(*s.begin());
    }
  }
}

int main() {
  /*
  freopen("integral.in","r",stdin);
  freopen("integral.out","w",stdout);
  */
  int qq = 1;
  //int qq = 1e9;
  //int qq; scanf("%d\n", &qq);
  for(int casenum = 1; casenum <= qq; casenum++) {
    solve();
  }
  return 0;
}