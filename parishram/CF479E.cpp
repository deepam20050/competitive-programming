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

using mint = modint < 1'000'000'007 >;

const int N = 5005;

mint pref[N];
mint dp[2][N];
int n, a, b, k;

mint sum (int curr, int l, int r, int idx) {
  l = max(l, 1);
  r = min(r, n);
  auto x = pref[r] - pref[l - 1] - dp[curr ^ 1][idx];
  if (l <= b && b <= r) {
    x -= dp[curr ^ 1][b];
  }
  return x;
}

int main () {
  scanf("%d %d %d %d", &n, &a, &b, &k);
  FOR(i, 1, n + 1) {
    dp[k & 1][i] = i == b ? 0 : 1;
    pref[i] = pref[i - 1] + dp[k & 1][i];
  }
  for (int i = k - 1; i >= 1; --i) {
    FOR(j, 1, n + 1) {
      if (j == b) continue;
      int diff = abs(b - j) - 1;
      dp[i & 1][j] = sum(i & 1, j - diff, j + diff, j);
    }
    FOR(j, 1, n + 1) {
      pref[j] = pref[j - 1] + dp[i & 1][j];
    }
  }
  int diff = abs(b - a) - 1;
  printf("%d\n", sum(0, a - diff, a + diff, a).val);
  return 0;
}
