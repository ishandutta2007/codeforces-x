#include <bits/stdc++.h>
using namespace std;
#define rep(it,st,en) for(int it=(st);it<(int)(en);++it)
#define allof(c) (c).begin(), (c).end()
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef long long ll; 
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
const int INF=(int)1e9; 
const double EPS=(ld)1e-7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi v(n);
    rep(i,0,n)cin>>v[i];
    ll t=*min_element(allof(v));
    rotate(v.begin(),min_element(allof(v)),v.end());
    ll mxcnt=0;
    ll cnt=0;
    rep(i,0,n){
        if(v[i]<=t)cnt=0;
        else cnt++;
        mxcnt=max(cnt,mxcnt);
    }
    cout<<t*n+mxcnt<<endl;
    return 0;
}