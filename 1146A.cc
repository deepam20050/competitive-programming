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
  int n; lli w; cin >> n >> w;
  vector < pii > a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(all(a), greater < pii > ());
  lli s = 0;
  vector < int > ans;
  lli limit = w + 1 >> 1ll;
  for (auto [val, idx] : a) {
    if (s + val <= w) {
      s += val;
      ans.emplace_back(idx);
    }
    if (limit <= s && s <= w) {
      cout << sz(ans) << '\n';
      for (auto &x : ans) {
        cout << x + 1 << " ";
      }
      cout << '\n';
      return;
    }
  }
  cout << "-1\n";
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