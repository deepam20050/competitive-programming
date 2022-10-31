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
  int n;
  cin >> n;
  vector < int > v(n);
  for (auto &e : v) {
    cin >> e;
  }
  auto v2 = v;
  sort(all(v2));
  int ans = (1 << 20) - 1;
  for (int i = 0; i < n; ++i) {
    if (v[i] != v2[i]) {
      ans &= v[i] & v2[i];
    }
  }
  cout << ans << '\n';
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