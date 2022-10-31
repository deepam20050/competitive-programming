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

using mint = modint < 998244353 >;

const int N = 3e5 + 5;

mint fact[N];
mint inv_fact[N];

inline mint nCk (int n, int k) {
  return k > n ? 0 : fact[n] * inv_fact[k] * inv_fact[n - k];
}

inline void genFacAndInv () {
  fact[0] = 1;
  inv_fact[0] = 1;
  FOR(i, 1, N) {
    fact[i] = fact[i - 1] * i;
    inv_fact[i] = fact[i].inv();
  }
}

vector < pii > points;

int main () {
  genFacAndInv();
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    points.eb(l, 0);
    points.eb(r, 1);
  }
  sort(all(points));
  mint ans = 0;
  int cnt = 0;
  for (auto &[x, t]: points) {
    if (t == 0) {
      ans -= nCk(cnt, k);
      ans += nCk(++cnt, k);
    } else {
      --cnt;
    }
  }
  printf("%d\n", ans.val);
  return 0;
}
