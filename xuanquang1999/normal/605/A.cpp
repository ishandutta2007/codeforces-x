//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, a[maxN], f[maxN], ans;
map<int, int> m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    m[0];

    fto(i, 1, n) {
        map<int, int>::iterator it = (--m.upper_bound(a[i]));
        if (it != m.end() && a[i]-it->ff == 1) {
            m[a[i]] = m[a[i]-1]+1;
            m.erase(a[i]-1);
            ans = max(ans, m[a[i]]);
        }
        else {
            m[a[i]] = 1;
            ans = max(ans, 1);
        }
    }
//    forit(it, m) printf("%d %d\n", it->ff, it->ss);

    cout << n-ans;

    return 0;
}