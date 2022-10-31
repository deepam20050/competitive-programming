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
  int n, k; cin >> n >> k;
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  if (k >= 3) {
    cout << *max_element(all(a)) << '\n';
  } else if (k == 2) {
    cout << max(a.front(), a.back()) << '\n';
  } else {
    cout << *min_element(all(a)) << '\n';
  }
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