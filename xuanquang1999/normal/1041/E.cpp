#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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

const int MAXN = 1005;

int n, a[MAXN], b[MAXN], ans[MAXN];
bool avail[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) scanf("%d%d", &a[i], &b[i]);

    fto(i, 1, n-1) {
        if (b[i] != n) {
            puts("NO");
            return 0;
        }
    }

    sort(a+1, a+n);

    ans[n] = n;

//    fto(i, 1, n-1) printf("%d ", a[i]);
//    puts("");

    memset(avail, true, sizeof avail);

    fto(i, 1, n-1) {
        if (a[i] < i) {
            puts("NO");
            return 0;
        }
        fdto(j, a[i], 1) {
            if (avail[j]) {
                avail[j] = false;
                ans[i] = j;
                break;
            }
        }
    }

    puts("YES");
    fto(i, 1, n-1) printf("%d %d\n", ans[i], ans[i+1]);

    return 0;
}