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
#define lb lower_bound
#define ub upper_bound

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

const int N = 1e5 + 5;

string s;
int zeros[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  cin >> s;
  s = " " + s;
  FOR(i, 1, n + 1) {
    zeros[i] = zeros[i - 1] + (int)(s[i] == '0');
  }
  while (q--) {
    int l, r; cin >> l >> r;
    int m = zeros[r] - zeros[l - 1];
    int x = r - l + 1 - m;
    if (x == 0) {
      cout << 0 << '\n';
    } else if (m == 0) {
      mint ans = 2;
      ans = ans.pow(x) - mint(1);
      cout << ans.val << '\n';
    } else {
      mint ans1 = 2;
      ans1 = ans1.pow(x) - mint(1);
      mint ans2 = 2;
      ans2 = ans2.pow(x) - mint(1);
      ans2 = ans2 * (mint(2).pow(m) - mint(1));
      ans1 += ans2;
      cout << ans1.val << '\n';
    }
  }
  return 0;
}