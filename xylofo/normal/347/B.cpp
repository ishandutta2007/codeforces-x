#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long int ll; 
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int a[101010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    bool b=true;
    int cnt=1;
    rep(i,0,n){
        cin>>a[i];
        if(a[i]==i)cnt++;
        if(a[i]<i && a[a[i]]==i && b){
            b=false;
            cnt++;
        }
    }
    cout<<min(cnt,n)<<endl;
    return 0;
}