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

const int N = 2e5 + 5;

bitset < N > not_used;
int a[N], pos[N], b[N];

void solve () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    not_used[i] = 1;
    scanf("%d", a + i);
    pos[a[i]] = i;
  }
  FOR(i, 0, k) {
    scanf("%d", b + i);
    not_used[pos[b[i]]] = 0;
  }
  mint ans = 1;
  FOR(i, 0, k) {
    int idx = pos[b[i]];
    int cnt = 0;
    if (idx + 1 < n && not_used[idx + 1]) {
      ++cnt;
    }
    if (idx - 1 >= 0 && not_used[idx - 1]) {
      ++cnt;
    }
    if (cnt == 2) {
      ans += ans;
    }
    if (cnt == 0) {
      puts("0");
      return;
    }
    not_used[idx] = 1;
  }
  printf("%d\n", ans.val);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
