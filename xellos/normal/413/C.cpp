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
#define OVER9000 1234567890123456780LL
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-10
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<long long> P(N);
	for(int i =0; i < N; i++) cin >> P[i];
	vector<bool> isA(N,false);
	for(int i =0; i < M; i++) {
		int a;
		cin >> a;
		isA[--a] =true;}

	long long ans =0;
	vector<long long> A;
	for(int i =0; i < N; i++) {
		if(isA[i]) A.push_back(P[i]);
		else ans +=P[i];}

	sort(A.begin(),A.end());
	for(int i =A.size()-1; i >= 0; i--) ans +=max(ans,A[i]);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing