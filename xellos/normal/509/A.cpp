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
using namespace std;
// mylittledoge

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector< vector<long long> > C(n,vector<long long>(n,0));
	for(int i =0; i < n; i++) C[i][0] =C[0][i] =1;
	long long ans =1;
	for(int i =1; i < n; i++) for(int j =1; j < n; j++) {
		C[i][j] =C[i-1][j]+C[i][j-1];
		ans =max(ans,C[i][j]);}
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing