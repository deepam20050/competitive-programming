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


void test_case() {
  int n; cin >> n;
  vector < int > odd, even;
  vector < pii > ans;
  for (int i = 1; i <= n + n; ++i) {
    int x; cin >> x;
    (x & 1) ? odd.emplace_back(i) : even.emplace_back(i);
  }
  for (int i = 0; i + 1 < sz(odd); i += 2) {
    ans.emplace_back(odd[i], odd[i + 1]);
  }
  for (int i = 0; i + 1 < sz(even); i += 2) {
    ans.emplace_back(even[i], even[i + 1]);
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << ans[i].first << " " << ans[i].second << '\n';
  }
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}