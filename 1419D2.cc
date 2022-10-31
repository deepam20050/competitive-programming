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

const int N = 1e5 + 2;

int a[N];

void test_case() {
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  function < bool (int) > f = [&] (int x) {
    if (x + x + 1 > n) {
      return 0;
    }
    vector < int > small;
    for (int i = 0; i < x; ++i) {
      small.emplace_back(a[i]);
    }
    vector < int > big;
    for (int j = n - (x + 1), r = x + 1; j >= 0 && r > 0; ++j, --r) {
      big.emplace_back(a[j]);
    }
    for (int i = 0; i < x; ++i) {
      if (small[i] >= big[i] || small[i] >= big[i + 1]) {
        return 0;
      }
    }
    return 1;
  };
  sort(a, a + n);
  int l = 0, r = n;
  for (int i = 0; i < 20; ++i) {
    int midx = l + r >> 1;
    if (f(midx)) {
      l = midx;
    } else {
      r = midx;
    }
  }
  f(l);
  cout << l << '\n';
  int x = l;
  for (int r = 1, i = 0, j = n - (x + 1); r <= x + x + 1; ++r) {
    if (r & 1) {
      cout << a[j++] << " ";
    } else {
      cout << a[i++] << " ";
    }
  }
  for (int i = x; i < n - (x + 1); ++i) {
    cout << a[i] << " ";
  }
  cout << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}