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

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

vector < int > divs[N];
int curr[N];
int dp[N];

inline int add (int x, int y) {
  x += y;
  return x >= MOD ? x -= MOD : x;
}

void test_case() {
  int n; cin >> n;
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    for (auto &d : divs[x]) {
      curr[d] = dp[d - 1];
    }
    for (auto &d : divs[x]) {
      dp[d] = add(dp[d], curr[d]);
    }
  }
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    ans = add(ans, dp[i]);
  }
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      divs[j].emplace_back(i);
    }
  }
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}