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

const int MN = 10055;

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

const int N = 1005;

mint dp[N];
int a[N];

int main () {
  genFacAndInv();
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  dp[n + 1] = 1;
  mint ans = 0;
  for (int i = n; i >= 1; --i) {
    if (a[i] <= 0) {
      continue;
    }
    for (int j = i + a[i] + 1; j <= n + 1; ++j) {
      dp[i] += dp[j] * nCk(j - i - 1, a[i]);
    }
    ans += dp[i];
  }
  printf("%d\n", ans.val);
  return 0;
}
