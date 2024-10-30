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
#define maxL 1100
#define MOD 1000000007
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

bool isLucky(int x) {
    while (x > 0) {
        if (x%10 != 4 && x%10 != 7) return false;
        x /= 10;
    }
    return true;
}

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int n, k, cntLucky[maxL], cntUnlucky, dp[maxL][maxL], fact[maxN], invFact[maxN];
map<int, int> id;

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return ((1LL*invFact[k]*invFact[n-k])%MOD * 1LL*fact[n])%MOD;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) {
        int x; scanf("%d", &x);
        if (isLucky(x)) {
            if (!id[x]) id[x] = sz(id);
            ++cntLucky[id[x]];
        } else ++cntUnlucky;
    }

    fact[0] = invFact[0] = 1;
    fto(i, 1, n) {
        fact[i] = (1LL*fact[i-1]*i)%MOD;
        invFact[i] = power(fact[i], MOD-2);
    }

    dp[0][0] = 1;
    fto(i, 1, sz(id)) {
        fto(j, 0, i) dp[i][j] = (dp[i-1][j] + 1LL*dp[i-1][j-1]*cntLucky[i])%MOD;
    }

//    fto(i, 0, sz(id)) {
//        fto(j, 0, i) printf("%d ", dp[i][j]);
//        puts("");
//    }
//    fto(i, 0, k) printf("%d %d\n", fact[i], invFact[i]);
//    debug(C(3, 2));
    int ans = 0;
    fto(j, 0, sz(id)) ans = (ans + 1LL*dp[sz(id)][j]*C(cntUnlucky, k-j))%MOD;
    printf("%d", ans);

    return 0;
}