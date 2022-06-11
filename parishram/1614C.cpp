#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = int64_t;
using pii = pair < int, int >;

// Credits : https://codeforces.com/contest/1420/submission/93731409
template < int M >
struct modint {
  int val = 0;
  modint () {}
  modint (int x) : val(x) {
    while (val < 0) val += M;
    while (val >= M) val -= M;
  }
  modint (long long x): val(x % M) {
    if (val < 0) val += M;
  }
  modint operator+= (modint oth) {
    val += oth.val;
    if (val >= M) val -= M;
    return *this;
  }
  modint operator-= (modint oth) {
    val -= oth.val;
    if (val < 0) val += M;
    return *this;
  }
  modint operator*= (modint oth) {
    val = val * 1LL * oth.val % M;
    return *this;
  }
  void operator++ () {
    ++val;
    if (val == M) val = 0;
  }
  void operator-- () {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }
  modint operator- () {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }
  modint& operator/= (modint const& b) { 
    return *this *= inv(b);
  }
  int mod() {
    return M;
  }
  template < class T >
  modint pow (T x) {
    modint base = val;
    modint res = 1;
    while (x > 0) {
      if (x & 1) res *= base;
      base *= base;
      x >>= 1;
    }
    return res;
  }
  modint pow (lli x) {
    modint base = val;
    modint res = 1;
    while (x > 0LL) {
      if (x & 1LL) res *= base;
      base *= base;
      x >>= 1LL;
    }
    return res;
  }
  modint inv () {
    return pow(M - 2);
  }
  friend modint operator+ (modint a, modint b) {
    return modint(a) += b;
  }
  friend modint operator- (modint a, modint b) {
    return modint(a) -= b;
  }
  friend modint operator* (modint a, modint b) {
    return modint(a) *= b;
  }
  friend bool operator== (modint a, modint b) {
    return a.val == b.val;
  }
  friend bool operator!= (modint a, modint b) {
    return a.val != b.val;
  }
  friend modint operator/(modint a, modint const b) { 
    return a /= b;
  }
  friend std::istream& operator>>(std::istream& istream, modint& a) {
    long long v; istream >> v; a = v; return istream;
  }
  friend std::ostream& operator<<(std::ostream& ostream, modint const& a) {
    return ostream << a.val;
  }
};

using mint = modint < 1'000'000'007 >;

const int N = 2e5 + 5;
const int LN = 30;

mint pw2[N];
int n, m;
int cnt[LN][N];
int bit[LN];

void init() {
  pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw2[i] = pw2[i - 1] + pw2[i - 1];
  }
}

void test_case() {
  cin >> n >> m;
  for (int i = 0; i < LN; ++i) {
    fill(cnt[i] + 1, cnt[i] + n + 1, 0);
  }
  memset(bit, 0, sizeof bit);
  for (int i = 0; i < m; ++i) {
    int l, r, x; cin >> l >> r >> x;
    int c = r - l + 1;
    for (int j = 0; j < LN; ++j) {
      if (x >> j & 1) {
        ++cnt[j][l];
        --cnt[j][r + 1];
      }
    }
  }
  for (int i = 0; i < LN; ++i) {
    for (int j = 1; j <= n; ++j) {
      cnt[i][j] += cnt[i][j - 1];
      if (cnt[i][j] > 0) {
        ++bit[i];
      }
    }
  }
  mint ans = 0;
  for (int i = 0; i < LN; ++i) {
    int on = bit[i];
    int off = n - bit[i];
    mint mul = 1 << i;
    if (on >= 1) {
      ans += mul * pw2[on - 1] * pw2[off];
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}