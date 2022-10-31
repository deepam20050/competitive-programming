#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
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
  int mod() {
    return M;
  }
  modint pow (int x) {
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
};

using mint = modint < 998244353 >;

const int MNX = 2e5 + 5;

mint fact[MNX];
mint inv_fact[MNX];

inline mint nCk (int n, int k) {
  return k > n ? 0 : fact[n] * inv_fact[k] * inv_fact[n - k];
}

inline void genFacAndInv () {
  fact[0] = 1;
  inv_fact[0] = 1;
  FOR(i, 1, MNX) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = fact[i].inv();
  }
}

void solve () {
  int n;
  scanf("%d", &n);
  map < int, int > cnt;
  vector < int > v(n);
  for (auto &e : v) {
    scanf("%d", &e);
    ++cnt[e];
  }
  sort(all(v));
  v.erase(unique(all(v)), v.end());
  reverse(all(v));
  if (sz(v) > 1 && cnt[v[0]] == 1 && v[0] - v[1] > 1) {
    puts("0");
    return;
  }
  reverse(all(v));
  mint ans = fact[n];
  if (sz(v) > 1 && cnt[v.back()] == 1) {
    mint x = cnt[v[sz(v) - 2]] + 1;
    ans = ans - fact[n] *  x.inv();
  }
  printf("%d\n", ans.val);
}

int main () {
  genFacAndInv();
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
