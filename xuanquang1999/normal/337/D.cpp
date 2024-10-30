//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 100005
#define oo 1000000007
#define EPS 1e-9

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, k, r, up[maxN], down[2][maxN];
bool marked[maxN];
vector<int> g[maxN];

void CalcDown(int u, int p) {
    if (marked[u]) down[0][u] = 0;
    forit(it, g[u]) {
        int v = *it;
        if (v != p) {
            CalcDown(v, u);
            if (down[0][v]+1 > down[0][u]) {
                down[1][u] = down[0][u];
                down[0][u] = down[0][v]+1;
            } else down[1][u] = max(down[1][u], down[0][v]+1);
        }
    }
}

void CalcUp(int u, int p) {
    forit(it, g[u]) {
        int v = *it;
        if (v != p) {
            int maxDown = (down[0][u] == down[0][v]+1) ? down[1][u] : down[0][u];
            up[v] = max(up[u], maxDown)+1;
            CalcUp(v, u);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &k, &r);
    fto(i, 1, k) {
        int x; scanf("%d", &x);
        marked[x] = true;
    }
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    fto(u, 1, n) up[u] = down[0][u] = down[1][u] = -oo;

    CalcDown(1, -1);
    CalcUp(1, -1);

    int ans = 0;
    fto(u, 1, n) {
        if (up[u] <= r && down[0][u] <= r) {
            ++ans;
            //debug(u);
        }
    }
    printf("%d", ans);

    return 0;
}