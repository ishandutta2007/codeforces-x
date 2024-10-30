#pragma GCC optimize("O3,unroll-loops")
#include <algorithm>
#include <cassert>
#include <istream>
#include <numeric>
#include <ostream>
#include <type_traits>
#ifdef _MSC_VER
#include <intrin.h>
#endif
#include <utility>
#ifdef _MSC_VER
#include <intrin.h>
#endif
namespace atcoder {
namespace internal {
constexpr long long safe_mod(long long x, long long m) {
  x %= m;
  if (x < 0) x += m;
  return x;
}
struct barrett {
  unsigned int _m;
  unsigned long long im;
  explicit barrett(unsigned int m)
      : _m(m), im((unsigned long long)(-1) / m + 1) {}
  unsigned int umod() const { return _m; }
  unsigned int mul(unsigned int a, unsigned int b) const {
    unsigned long long z = a;
    z *= b;
#ifdef _MSC_VER
    unsigned long long x;
    _umul128(z, im, &x);
#else
    unsigned long long x =
        (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
    unsigned int v = (unsigned int)(z - x * _m);
    if (_m <= v) v += _m;
    return v;
  }
  unsigned int mod(unsigned long long z) const {
    unsigned long long x = (unsigned long long)(((__uint128_t)z * im) >> 64);
    unsigned int v = (unsigned int)(z - x * _m);
    if (v >= _m) v += _m;
    return v;
  }
};
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
  if (m == 1) return 0;
  unsigned int _m = (unsigned int)(m);
  unsigned long long r = 1;
  unsigned long long y = safe_mod(x, m);
  while (n) {
    if (n & 1) r = (r * y) % _m;
    y = (y * y) % _m;
    n >>= 1;
  }
  return r;
}
constexpr bool is_prime_constexpr(int n) {
  if (n <= 1) return false;
  if (n == 2 || n == 7 || n == 61) return true;
  if (n % 2 == 0) return false;
  long long d = n - 1;
  while (d % 2 == 0) d /= 2;
  constexpr long long bases[3] = {2, 7, 61};
  for (long long a : bases) {
    long long t = d;
    long long y = pow_mod_constexpr(a, t, n);
    while (t != n - 1 && y != 1 && y != n - 1) {
      y = y * y % n;
      t <<= 1;
    }
    if (y != n - 1 && t % 2 == 0) return false;
  }
  return true;
}
template <int n>
constexpr bool is_prime = is_prime_constexpr(n);
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
  a = safe_mod(a, b);
  if (a == 0) return {b, 0};
  long long s = b, t = a;
  long long m0 = 0, m1 = 1;
  while (t) {
    long long u = s / t;
    s -= t * u;
    m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b
    auto tmp = s;
    s = t;
    t = tmp;
    tmp = m0;
    m0 = m1;
    m1 = tmp;
  }
  if (m0 < 0) m0 += b / s;
  return {s, m0};
}
constexpr int primitive_root_constexpr(int m) {
  if (m == 2) return 1;
  if (m == 167772161) return 3;
  if (m == 469762049) return 3;
  if (m == 754974721) return 11;
  if (m == 998244353) return 3;
  int divs[20] = {};
  divs[0] = 2;
  int cnt = 1;
  int x = (m - 1) / 2;
  while (x % 2 == 0) x /= 2;
  for (int i = 3; (long long)(i)*i <= x; i += 2)
    if (x % i == 0) {
      divs[cnt++] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) divs[cnt++] = x;
  for (int g = 2;; g++) {
    bool ok = true;
    for (int i = 0; i < cnt; i++)
      if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
        ok = false;
        break;
      }
    if (ok) return g;
  }
}
template <int m>
constexpr int primitive_root = primitive_root_constexpr(m);
unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
  unsigned long long ans = 0;
  while (true) {
    if (a >= m) {
      ans += n * (n - 1) / 2 * (a / m);
      a %= m;
    }
    if (b >= m) {
      ans += n * (b / m);
      b %= m;
    }
    unsigned long long y_max = a * n + b;
    if (y_max < m) break;
    n = (unsigned long long)(y_max / m);
    b = (unsigned long long)(y_max % m);
    std::swap(m, a);
  }
  return ans;
}
}  // namespace internal
}  // namespace atcoder
#include <cassert>
#include <numeric>
#include <type_traits>
namespace atcoder {
namespace internal {
#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value, __uint128_t,
                              unsigned __int128>;
template <class T>
using is_integral =
    typename std::conditional<std::is_integral<T>::value ||
                                  is_signed_int128<T>::value ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_signed<T>::value) ||
                                  is_signed_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value, make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;
#else
template <class T>
using is_integral = typename std::is_integral<T>;
template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type, std::false_type>::type;
template <class T>
using to_unsigned =
    typename std::conditional<is_signed_int<T>::value, std::make_unsigned<T>,
                              std::common_type<T>>::type;
#endif
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;
template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;
template <class T>
using to_unsigned_t = typename to_unsigned<T>::type;
}  // namespace internal
}  // namespace atcoder
namespace atcoder {
namespace internal {
struct modint_base {};
struct static_modint_base : modint_base {};
template <class T>
using is_modint = std::is_base_of<modint_base, T>;
template <class T>
using is_modint_t = std::enable_if_t<is_modint<T>::value>;
}  // namespace internal
template <int m, std::enable_if_t<(1 <= m)> * = nullptr>
struct static_modint : internal::static_modint_base {
  using mint = static_modint;

 public:
  static constexpr int mod() { return m; }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }
  static_modint() : _v(0) {}
  template <class T, internal::is_signed_int_t<T> * = nullptr>
  static_modint(T v) {
    long long x = (long long)(v % (long long)(umod()));
    if (x < 0) x += umod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T> * = nullptr>
  static_modint(T v) {
    _v = (unsigned int)(v % umod());
  }
  unsigned int val() const { return _v; }
  mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint &operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v -= rhs._v;
    if (_v >= umod()) _v += umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    unsigned long long z = _v;
    z *= rhs._v;
    _v = (unsigned int)(z % umod());
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }
  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    if (prime) {
      assert(_v);
      return pow(umod() - 2);
    } else {
      auto eg = internal::inv_gcd(_v, m);
      assert(eg.first == 1);
      return eg.second;
    }
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }
  friend std::istream &operator>>(std::istream &in, mint &x) {
    long long tmp;
    in >> tmp;
    x = tmp;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.val();
  }

 private:
  unsigned int _v;
  static constexpr unsigned int umod() { return m; }
  static constexpr bool prime = internal::is_prime<m>;
};
template <int id>
struct dynamic_modint : internal::modint_base {
  using mint = dynamic_modint;

 public:
  static int mod() { return (int)(bt.umod()); }
  static void set_mod(int m) {
    assert(1 <= m);
    bt = internal::barrett(m);
  }
  static mint raw(int v) {
    mint x;
    x._v = v;
    return x;
  }
  dynamic_modint() : _v(0) {}
  template <class T, internal::is_signed_int_t<T> * = nullptr>
  dynamic_modint(T v) {
    long long x = (long long)(v % (long long)(mod()));
    if (x < 0) x += mod();
    _v = (unsigned int)(x);
  }
  template <class T, internal::is_unsigned_int_t<T> * = nullptr>
  dynamic_modint(T v) {
    _v = (unsigned int)(v % mod());
  }
  unsigned int val() const { return _v; }
  mint &operator++() {
    _v++;
    if (_v == umod()) _v = 0;
    return *this;
  }
  mint &operator--() {
    if (_v == 0) _v = umod();
    _v--;
    return *this;
  }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  mint &operator+=(const mint &rhs) {
    _v += rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator-=(const mint &rhs) {
    _v += mod() - rhs._v;
    if (_v >= umod()) _v -= umod();
    return *this;
  }
  mint &operator*=(const mint &rhs) {
    _v = bt.mul(_v, rhs._v);
    return *this;
  }
  mint &operator/=(const mint &rhs) { return *this = *this * rhs.inv(); }
  mint operator+() const { return *this; }
  mint operator-() const { return mint() - *this; }
  mint pow(long long n) const {
    assert(0 <= n);
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inv() const {
    auto eg = internal::inv_gcd(_v, mod());
    assert(eg.first == 1);
    return eg.second;
  }
  friend mint operator+(const mint &lhs, const mint &rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint &lhs, const mint &rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint &lhs, const mint &rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint &lhs, const mint &rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint &lhs, const mint &rhs) {
    return lhs._v == rhs._v;
  }
  friend bool operator!=(const mint &lhs, const mint &rhs) {
    return lhs._v != rhs._v;
  }
  friend std::istream &operator>>(std::istream &in, mint &x) {
    long long tmp;
    in >> tmp;
    x = tmp;
    return in;
  }
  friend std::ostream &operator<<(std::ostream &out, const mint &x) {
    return out << x.val();
  }

 private:
  unsigned int _v;
  static internal::barrett bt;
  static unsigned int umod() { return bt.umod(); }
};
template <int id>
internal::barrett dynamic_modint<id>::bt(998244353);
using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;
namespace internal {
template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;
template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;
template <class>
struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};
template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;
}  // namespace internal
}  // namespace atcoder
#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <utility>
#include <vector>
using mint = atcoder::modint1000000007;
template <typename T1, typename T2>
void checkmax(T1 &x, T2 y) {
  if (x < y) x = y;
}
template <typename T1, typename T2>
void checkmin(T1 &x, T2 y) {
  if (x > y) x = y;
}\
int n, k, x[50], y[50], z[50], w[50][50], cnty[50];
std::pair<int, int> a[50];
mint fac[100001];
bool vis[50];
__gnu_pbds::gp_hash_table<long long, mint> f[51], g[51];
int main(int argc, char const *argv[]) {
  std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 0; i < k; i++) {
    std::cin >> a[i].first >> a[i].second >> z[i];
    z[i] = (z[i] + mint::mod() - 1) % mint::mod();
  }
  fac[0] = mint::raw(1);
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * mint::raw(i);
  for (int i = 0; i < k; i++) x[i] = a[i].first;
  std::sort(x, x + k);
  int cx = std::unique(x, x + k) - x;
  for (int i = 0; i < k; i++)
    a[i].first = std::lower_bound(x, x + cx, a[i].first) - x;
  for (int i = 0; i < k; i++) y[i] = a[i].second;
  std::sort(y, y + k);
  int cy = std::unique(y, y + k) - y;
  for (int i = 0; i < k; i++)
    a[i].second = std::lower_bound(y, y + cy, a[i].second) - y;
  for (int i = 0; i < cx; i++) std::fill(w[i], w[i] + cy, -1);
  for (int i = 0; i < k; i++) w[a[i].first][a[i].second] = z[i];
  for (int i = 0; i < k; i++) cnty[a[i].second]++;
  f[0][0] = mint::raw(1);
  while (true) {
    int p = -1;
    for (int i = 0; i < cy; i++)
      if (cnty[i] && (p == -1 || cnty[i] < cnty[p])) p = i;
    if (p == -1) break;
    for (int i = 0; i < cx; i++)
      if (!vis[i] && w[i][p] != -1) {
        vis[i] = true;
        long long curfull = (1LL << cy) - 1;
        std::vector<int> v;
        for (int j = 0; j < cy; j++)
          if (w[i][j] != -1) {
            v.emplace_back(j);
            if (!--cnty[j]) curfull ^= 1LL << j;
          }
        for (int j = 0; j <= k; j++) {
          for (const auto &[S, f] : f[j]) {
            g[j][S & curfull] += f;
            if (j < k)
              for (const auto o : v)
                if (~S >> o & 1)
                  g[j + 1][(S | 1LL << o) & curfull] += f * w[i][o];
          }
          std::swap(f[j], g[j]), g[j].clear();
        }
      }
  }
  mint ans;
  for (int i = 0; i <= k; i++)
    for (const auto &[S, f] : f[i]) ans += f * fac[n - i];
  std::cout << ans;
  return 0;
}