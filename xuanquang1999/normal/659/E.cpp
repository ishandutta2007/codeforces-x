//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define x first
#define y second
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

int n, m, ans, parent[maxN];
vector<int> ke[maxN];
bool visited[maxN], cycle;

void DFS(int u) {
    visited[u] = true;
    forit(it, ke[u]) {
        int v = *it;
        if (v == parent[u]) continue;
        parent[v] = u;
        if (visited[v]) cycle = true;
        else DFS(v);
    }
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);

    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v); ke[v].pb(u);
    }

    fto(u, 1, n) {
        if (!visited[u]) {
            cycle = false;
            DFS(u);
            ans += (1-cycle);
        }
    }

    cout << ans;

    return 0;
}