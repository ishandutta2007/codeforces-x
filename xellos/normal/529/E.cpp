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
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define pi 3.14159265359
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	vector<int> A(N);
	map<int,int> M;
	for(int i =0; i < N; i++) {
		cin >> A[i];
		for(int j =0; j <= K; j++) {
			if(M.find(A[i]*j) == M.end()) M[A[i]*j] =j;
			else M[A[i]*j] =min(M[A[i]*j],j);}
		}

	int Q;
	cin >> Q;
	for(int q =0; q < Q; q++) {
		int x;
		cin >> x;
		int ans =K+1;
		for(int i =0; i < N; i++) for(int j =0; j <= K; j++) {
			int y =x-A[i]*j;
			if(M.find(y) != M.end()) ans =min(ans,M[y]+j);}
		if(ans == K+1) ans =-1;
		cout << ans << "\n";}
	return 0;}

// look at my code
// my code is amazing