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

using mint = modint < 1000000007 >;

const int MN = 2e5 + 5;

mint fact[MN];
mint inv_fact[MN];

inline mint nCk (int n, int k) {
  return k > n ? 0 : fact[n] * inv_fact[k] * inv_fact[n - k];
}

inline void genFacAndInv () {
  fact[0] = 1;
  inv_fact[0] = 1;
  FOR(i, 1, MN + 1) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = fact[i].inv();
  }
}

const int N = 2e5 + 5;

mint pw[N];
mint dp[N][2];
int n, k;
mint ceven;

mint f (int i, int eq) {
  if (i < 0) {
    return 1;
  }
  auto &r = dp[i][eq];
  if (r != -1) {
    return r;
  }
  if (eq == 0) {
    return r = pw[n] * f(i - 1, 0);
  }
  if (n & 1) {
    return r = f(i - 1, 1) * (mint(1) + ceven);
  }
  return r = f(i - 1, 1) * ceven + f(i - 1, 0);
}

void solve () {
  scanf("%d %d", &n, &k);
  FOR(i, 0, k + 1) {
    dp[i][0] = dp[i][1] = -1;
  }
  ceven = 0;
  for (int i = 0; i < n; i += 2) {
    ceven += nCk(n, i);
  }
  printf("%d\n", f(k - 1, 1).val);
}

int main () {
  genFacAndInv();
  pw[0] = 1;
  FOR(i, 1, N) {
    pw[i] = pw[i - 1] + pw[i - 1];
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
