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

const int primes[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
const int N = 1 << 20;
const int M = 72;

mint dp[2][N];
mint f[2][M];
int mask[M];
int n;

int main () {
  scanf("%d", &n);
  FOR(i, 0, M) {
    f[0][i] = 1;
  }
  FOR(i, 2, M) {
    int x = i;
    FOR(j, 0, 19) {
      while (x % primes[j] == 0) {
        mask[i] ^= 1 << j;
        x /= primes[j];
      }
    }
  }
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    f[0][x] = f[1][x] = (f[0][x] + f[1][x]);
  }
  dp[0][0] = 1;
  FOR(i, 0, 71) {
    int curr = i & 1;
    int nxt = curr ^ 1;
    FOR(msk, 0, N) {
      dp[nxt][msk ^ mask[i]] += dp[curr][msk] * f[1][i];
      dp[nxt][msk] += dp[curr][msk] * f[0][i];
    }
    FOR(msk, 0, N) {
      dp[curr][msk] = 0;
    }
  }
  dp[1][0] -= (mint)1;
  printf("%d\n", dp[1][0].val);
  return 0;
}
