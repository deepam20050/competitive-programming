// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
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

const int N = 5e5 + 5;
const int LN = 61;

lli arr[N];
mint pw2[LN];
int freq[LN];
mint sum[LN];
int n;

void solve () {
  scanf("%d", &n);
  FOR(i, 0, LN) {
    freq[i] = 0;
    sum[i] = 0;
  }
  FOR(i, 0, n) {
    scanf("%lld", arr + i);
    FOR(j, 0, LN) {
      freq[j] += arr[i] >> j & 1;
    }
  }
  FOR(i, 0, n) {
    mint cost = (mint) n * arr[i];
    FOR(j, 0, LN) if (!(arr[i] >> j & 1)) {
      cost += freq[j] * pw2[j];
    }
    FOR(j, 0, LN) if (arr[i] >> j & 1) {
      sum[j] += cost;
    }
  }
  mint ans = 0;
  FOR(i, 0, n) {
    FOR(j, 0, LN) {
      if (arr[i] >> j & 1) {
        ans += sum[j] * pw2[j];
      }
    }
  }
  printf("%d\n", ans.val);
}

int main () {
  pw2[0] = 1;
  FOR(i, 1, LN) pw2[i] = pw2[i - 1] + pw2[i - 1];
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
