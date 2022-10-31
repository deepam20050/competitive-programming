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

const int N = 2e5 + 5;

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

using mint = modint < 998244353 >;

vector < int > g[N];
int d[2][N];
int pr[N];
bool used[N];
int lft[N], rgt[N];

void dfs (int u, int p, int i) {
  pr[u] = p;
  for (auto &to : g[u]) {
    if (to != p) {
      d[i][to] = d[i][u] + 1;
      dfs(to, u, i);
    }
  }
}

int cnt = 0;

void dfs2 (int u, int p, int depth) {
  lft[p] += d[0][p] == depth;
  rgt[p] += d[1][p] == depth;
  cnt += d[0][p] == depth || d[1][p] == depth;
  used[u] = 1;
  for (auto &to : g[u]) {
    if (!used[to]) {
      dfs2(to, p, depth + 1);
    }
  }
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  dfs(1, 0, 0);
  int l = max_element(d[0], d[0] + n + 1) - d[0];
  d[0][l] = 0;
  dfs(l, 0, 0);
  int r = max_element(d[0], d[0] + n + 1) - d[0];
  vector < int > dia;
  for (int x = r; x != 0; x = pr[x]) {
    dia.emplace_back(x);
    used[x] = 1;
  }
  d[1][r] = 0;
  dfs(r, 0, 1);
  mint total_right = 0;
  reverse(all(dia));
  for (auto &x : dia) {
    dfs2(x, x, 0);
    total_right += rgt[x];
  }
  mint ans = 0;
  for (auto &x : dia) {
    ans += lft[x] * total_right;
    total_right -= rgt[x];
  }
  ans += mint(2).pow(lft[dia.front()]) * mint(2).pow(rgt[dia.back()]);
  ans = mint(2).pow(cnt);
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