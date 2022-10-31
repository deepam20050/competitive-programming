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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  int m = *min_element(all(a));
  vector < int > pos;
  vector < pii > vals;
  for (int i = 0; i < n; ++i) {
    if (a[i] % m == 0) {
      vals.emplace_back(a[i], i);
      pos.emplace_back(i);
    }
  }
  sort(all(vals));
  int idx = 0;
  for (auto [val, ignore] : vals) {
    a[pos[idx++]] = val;
  }
  is_sorted(all(a)) ? cout << "YES\n" : cout << "NO\n";
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