#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> div, divg;
	for(int i = 1; i*i <= N; i++) if(N%i == 0) {
		div.push_back(i);
		if(i*i != N) divg.push_back(N/i);
	}
	for(int i = (int)divg.size()-1; i >= 0; i--) div.push_back(divg[i]);
	for(int i = (int)div.size()-1; i >= 0; i--)
		cout << (1LL*N*(N/div[i]-1)+2LL*N/div[i])/2 << ((i == 0) ? "\n" : " ");
	return 0;
}

// look at my code
// my code is amazing