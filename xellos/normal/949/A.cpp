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
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

typedef long long cat;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	string S;
	cin >> S;
	int L = S.length(), cnt = 0;
	for(int i = 0; i < L; i++) {
		if(S[i] == '1') cnt--;
		else cnt++;
	}
	vector< vector<int> > Z;
	vector<int> tp[2];
	for(int i = 0; i < L; i++) {
		if(S[i] == '1') {
			if(tp[0].empty()) {
				cout << "-1\n";
				return 0;
			}
			Z[tp[0].back()].push_back(i);
			tp[1].push_back(tp[0].back());
			tp[0].pop_back();
			continue;
		}
		// S[i] == '0'
		if((int)tp[0].size()+(int)tp[1].size() < cnt) {
			tp[0].push_back(Z.size());
			Z.push_back(vector<int>(1, i));
			continue;
		}
		if(tp[1].empty()) {
			cout << "-1\n";
			return 0;
		}
		Z[tp[1].back()].push_back(i);
		tp[0].push_back(tp[1].back());
		tp[1].pop_back();
	}
	if(tp[1].empty()) {
		cout << Z.size() << "\n";
		for(int i = 0; i < (int)Z.size(); i++) {
			cout << Z[i].size();
			for(int j = 0; j < (int)Z[i].size(); j++) cout << " " << Z[i][j]+1;
			cout << "\n";
		}
		return 0;
	}
	cout << "-1\n";
	return 0;}

// look at my code
// my code is amazing