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
#define maxN 5005
#define oo 2000000007
#define EPS 1e-9
#define sz(a) (int)a.size()

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

int n, a[maxN], l[maxN], r[maxN], c[maxN][maxN], f[maxN];
bool valid[maxN][maxN], avail[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n) {
        if (l[a[i]] == 0) l[a[i]] = i;
    }
    fdto(i, n, 1) {
        if (r[a[i]] == 0) r[a[i]] = i;
    }
    fto(i, 1, n) {
        int minL = n+1, maxR = 0;
        fto(j, i, n) {
            minL = min(minL, l[a[j]]);
            maxR = max(maxR, r[a[j]]);
            valid[i][j] = (minL >= i && maxR <= j);
        }
    }
//    fto(i, 1, n) {
//        fto(j, 1, n) printf("%d ", valid[i][j]);
//        puts("");
//    }

    fto(i, 1, n) {
        memset(avail, false, sizeof avail);
        int cur = 0;
        fto(j, i, n) {
            c[i][j] = c[i][j-1];
            if (!avail[a[j]]) {
                c[i][j] ^= a[j];
                avail[a[j]] = true;
            }
        }
    }

    fto(i, 1, n) {
        f[i] = f[i-1];
        fto(j, 1, i) {
            if (valid[j][i]) f[i] = max(f[i], f[j-1]+c[j][i]);
        }
    }
    printf("%d", f[n]);

    return 0;
}