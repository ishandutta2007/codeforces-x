//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define maxK 20
#define oo 1000000000000000007LL

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

template <class T>
void read(vector<T> &v) {
    T x;
    cin >> x;
    v.pb(x);
}

int n, m;
map<int, int> _next[maxN];
vector<ii> ke[maxN];
ll d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        ke[u].pb(mp(v, c)); ke[v].pb(mp(u, c));
    }

    fto(u, 1, n) {
        int k, x;
        scanf("%d", &k);
        vector<int> v(k);
        fto(j, 0, k-1) scanf("%d", &v[j]);

        sort(v.begin(), v.end());
        fdto(i, k-1, 0) {
            if (i < k-1 && v[i+1]-v[i] == 1) _next[u][v[i]] = _next[u][v[i+1]];
            else _next[u][v[i]] = v[i]+1;
        }
    }

    fto(u, 1, n) d[u] = oo;
    d[1] = 0;
    set<ii> s;
    s.insert(mp(d[1], 1));
    while (!s.empty()) {
        int u = s.begin()->ss; s.erase(s.begin());
        forit(it, ke[u]) {
            int v = it->ff, c = it->ss;

            map<int, int>::iterator it2 = _next[u].find(d[u]);
            int x = (it2 != _next[u].end()) ? (it2->ss+c) : (d[u]+c);

            if (x < d[v]) {
                s.erase(mp(d[v], v));
                d[v] = x;
                s.insert(mp(d[v], v));
            }
        }
//        fto(u, 1, n) cout << d[u] << " ";
//        cout << endl;
    }

    cout << ((d[n] == oo) ? -1 : d[n]);

    return 0;
}