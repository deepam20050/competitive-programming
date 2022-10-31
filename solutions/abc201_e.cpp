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

using lli = long long;
using pii = pair < int, int >;

// Credits : https://codeforces.com/contest/1420/submission/93731409
template < int M > struct modint {
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
  friend std::istream& operator>> (std::istream& istream, modint& a) {
    long long v; istream >> v; a = v; return istream;
  }
  friend std::ostream& operator<< (std::ostream& ostream, modint const& a) {
    return ostream << a.val;
  }
};

using mint = modint < 1'000'000'007 >;

const int N = 2e5 + 5;
const int LN = 60;

lli d[N];
int cnt[LN];
vector < pair < int, lli > > g[N];

void dfs (int u, int p) {
  for (int i = 0; i < LN; ++i) {
    cnt[i] += d[u] >> i & 1;
  }
  for (auto [to, w] : g[u]) {
    if (to != p) {
      d[to] = d[u] ^ w;
      dfs(to, u);
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b; lli c; cin >> a >> b >> c;
    g[a].emplace_back(b, c);
    g[b].emplace_back(a, c);
  }
  dfs(1, 1);
  mint ans = 0;
  for (int i = 0; i < LN; ++i) {
    mint tmp = 1ll << i;
    tmp *= cnt[i] * 1ll * (n - cnt[i]);
    ans += tmp;
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}