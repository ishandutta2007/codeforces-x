// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <tr1/unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#define dibs reserve
#define OVER9000 234567890
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
// so much chocolate
#define ff first
#define ss second
#define uint unsigned int
// mylittlepony
using namespace std;

int main() {
	string s;
	cin >> s;
	int poc[3] ={0,0,0};
	for(int i =0; i < s.length(); i++) if(s[i] >= '1' && s[i] <= '3') poc[s[i]-'1']++;
	for(int i =0; i < poc[0]; i++) s[2*i] ='1';
	for(int i =poc[0]; i < poc[0]+poc[1]; i++) s[2*i] ='2';
	for(int i =poc[0]+poc[1]; i < poc[0]+poc[1]+poc[2]; i++) s[2*i] ='3';	
	cout << s << "\n";
    return 0;}
        
// look at my code
// my code is amazing