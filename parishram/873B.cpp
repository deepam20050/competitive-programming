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

using lli = int64_t;
using pii = pair < int, int >;

template < class T > bool ckmin (T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool ckmax (T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const int ZERO = 1e5 + 5;
const int N = 2 * ZERO;

int dp[N];
int n;
string s;

void test_case() {
  int n; cin >> n;
  cin >> s;
  fill(dp, dp + N, 1 << 20);
  dp[ZERO] = -1;
  int ans = 0;
  for (int i = 0, ones = 0, zeros = 0; i < n; ++i) {
    ones += s[i] == '1';
    zeros += s[i] == '0';
    ckmin(dp[ZERO + ones - zeros], i);
    ckmax(ans, i - dp[ZERO + ones - zeros]);
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}