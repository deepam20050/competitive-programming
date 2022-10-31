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

typedef long long lli;
typedef pair < int, int > pii;

int solve (int x, int y) {
  if (x % y == 0) {
    return y == 1 ? x - 1 : (int)1e9;
  }
  return x / y + solve(y, x % y);
}

void test_case() {
  int n; cin >> n;
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    ans = min(ans, solve(n, i));
  }
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  // cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}