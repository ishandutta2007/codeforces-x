// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <tr1/unordered_map>
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
#define dbl double
using namespace std;
using namespace std::tr1;
// mylittledoge

int main() {
	int N,M,D;
	scanf(" %d %d %d",&N,&M,&D);
	vector<int> V(N*M);
	for(int i =0; i < N*M; i++) scanf(" %d",&V[i]);
	sort(begin(V),end(V));
	int ans =0;
	for(int i =0; i < N*M; i++) {
		if((V[i]-V[(N*M)/2])%D != 0) {printf("-1\n"); return 0;}
		ans +=abs(V[i]-V[(N*M)/2])/D;}
	printf("%d\n",ans);
	return 0;}

// look at my code
// my code is amazing