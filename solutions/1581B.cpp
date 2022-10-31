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

typedef long long lli;
typedef pair < int, int > pii;

void test_case() {
  lli n, m, k; cin >> n >> m >> k;
  if (n - 1 <= m && m <= n * (n - 1) / 2) {
    if (k > 3 || (k == 3 && m == n * (n - 1) / 2)) {
      cout << "YES\n";
      return;
    }
    if (n == 1 && k > 1) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}