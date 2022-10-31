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

const int ND = 11;

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
    modint ans;
    ans.val = (val == 0) ? 0 : M - val;
    return ans;
  }
  int mod() {
    return M;
  }
  modint pow (int x) {
    modint base = val;
    modint ans = 1;
    while (x > 0) {
      if (x & 1) ans *= base;
      base *= base;
      x >>= 1;
    }
    return ans;
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

const int N = 1e5 + 5;

vector < int > v;
int freq[ND];
int n;
mint ans = 0;
int arr[N];

void solve0 (int l) {
  mint pw = 1;
  mint add = 0;
  FOR(i, 0, max(l, sz(v))) {
    if (i < sz(v)) {
      add += v[i] * pw;
      pw *= 10;
    }
    if (i < l) {
      pw *= 10;
    }
  }
  ans += add * freq[l];
}

void solve1 (int l) {
  mint pw = 1;
  mint add = 0;
  FOR(i, 0, max(l, sz(v))) {
    if (i < l) {
      pw *= 10;
    }
    if (i < sz(v)) {
      add += v[i] * pw;
      pw *= 10;
    }
  }
  ans += add * freq[l];
}

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", arr + i);
    int x = arr[i];
    int m = 0;
    while (x > 0) {
      ++m;
      x /= 10;
    }
    ++freq[m];
  }
  FOR(i, 0, n) {
    int x = arr[i];
    v.clear();
    while (x > 0) {
      v.eb(x % 10);
      x /= 10;
    }
    FOR(i, 0, ND) {
      if (!freq[i]) continue;
      solve0(i);
      solve1(i);
    }
  }
  printf("%d\n", ans.val);
  return 0;
}
