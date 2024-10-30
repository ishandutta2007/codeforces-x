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
#define maxN 105
#define oo 3000000000000000000LL

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

int n, m, k, a[maxN], b[maxN], par[maxN];
bool c[maxN][maxN], visited[maxN];

bool DFS(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    fto(v, 1, k) {
        if (c[u][v] && (!par[v] || DFS(par[v]))) {
            par[v] = u;
            return true;
        }
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    fto(i, 1, m) scanf("%d", &b[i]);

    fto(i, 1, n) {
        fto(j, 1, m) {
            if (abs(a[i]-b[j]) <= 1) c[i][j] = true;
        }
    }
    k = max(n, m);

    int ans = 0;
    fto(u, 1, k) {
        memset(visited, false, sizeof visited);
        if (DFS(u)) ++ans;
    }
    printf("%d", ans);

    return 0;
}