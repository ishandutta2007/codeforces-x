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
	map<int,int> X;
	for(int i =0; i < N; i++) {
		int a;
		cin >> a;
		X[a]++;}
	int M;
	cin >> M;
	vector< pair< pair<int,int>,int> > V(M);
	vector<int> B(M),C(M);
	for(int i =0; i < M; i++) cin >> B[i];
	for(int i =0; i < M; i++) cin >> C[i];
	pair<int,int> p =make_pair(-1,-1);
	int ans =0;
	for(int i =0; i < M; i++) if(make_pair(X[B[i]],X[C[i]]) > p) {
		ans =i;
		p =make_pair(X[B[i]],X[C[i]]);}
	cout << ans+1 << "\n";
	return 0;}

// look at my code
// my code is amazing