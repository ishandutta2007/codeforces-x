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
	int T;
	cin >> T;
	while(T--) {
		string S;
		cin >> S;
		int N = S.length();
		int sum = 0, cnt0 = 0, cnte = 0;
		for(int i = 0; i < N; i++) {
			sum += S[i]-'0';
			if((S[i]-'0')%2 == 0) cnte++;
			if(S[i] == '0') cnt0++;
		}
		if(!cnt0 || sum%3 != 0) {
			cout << "cyan\n";
			continue;
		}
		if(cnt0 >= 2 || cnte >= 2) cout << "red\n";
		else cout << "cyan\n";
	}
	return 0;
}

// look at my code
// my code is amazing