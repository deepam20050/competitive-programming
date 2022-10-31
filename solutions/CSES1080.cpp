#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

// Credits : https://codeforces.com/contest/1420/submission/93731409
template < int M > struct modint {
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
  modint& operator/= (modint const& b) { 
    return *this *= inv(b);
  }
  int mod() {
    return M;
  }
  template < class T >
  modint pow (T x) {
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
  friend modint operator/(modint a, modint const b) {
    return a /= b;
  }
  friend std::istream& operator>> (std::istream& istream, modint& a) {
    long long v; istream >> v; a = v; return istream;
  }
  friend std::ostream& operator<< (std::ostream& ostream, modint const& a) {
    return ostream << a.val;
  }
};

using mint = modint < 1'000'000'007 >;

const int N = 505;

string s;
int n;
mint dp[N][N];
mint pascal[N][N];

void test_case() {
  cin >> s;
  n = sz(s);
  for (int i = 0; i + 1 <= n; ++i) {
    dp[i + 1][i] = 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i + 1; j < n; j += 2) {
      for (int k = i + 1; k <= j; k += 2) {
        if (s[i] == s[k]) {
          dp[i][j] += dp[i + 1][k - 1] * dp[k + 1][j] * pascal[(j - i + 1) / 2][(k - i + 1)/ 2];
        }
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  pascal[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    pascal[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
    }
  }
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}