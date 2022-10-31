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
  int a[2] = {};
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++a[x - 1];
  }
  if (!a[0] || !a[1]) {
    for (int i = 0; i < n; ++i) {
      cout << (a[0] ? 1 : 2) << " ";
    }
  } else {
    cout << 2 << " " << 1 << " ";
    a[0] -= 1;
    a[1] -= 1;
    while (a[1]--) {
      cout << 2 << " ";
    }
    while (a[0]--) {
      cout << 1 << " ";
    }
  }
  cout << '\n';
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