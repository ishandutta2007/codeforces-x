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
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):x)
#define uint unsigned int
#define dbl long double
#define param vector<int>
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int T,K;
	cin >> T >> K;
	vector<int> ans(100000+tisic,0);
	ans[0] =1;
	int mod =1000000007;
	for(int i =1; i <= 100000; i++) {
		ans[i] =ans[i-1]+((i >= K)?ans[i-K]:0);
		if(ans[i] >= mod) ans[i] -=mod;}
	for(int i =1; i <= 100000; i++) {
		ans[i] =ans[i-1]+ans[i];
		if(ans[i] >= mod) ans[i] -=mod;}

	for(int q =0; q < T; q++) {
		int a,b;
		cin >> a >> b;
		int x =ans[b]-ans[a-1];
		if(x < 0) x +=mod;
		cout << x << "\n";}
	return 0;}

// look at my code
// my code is amazing