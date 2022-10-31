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
  if (n & 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (j - i <= n / 2) {
          cout << 1 << " ";
        } else {
          cout << -1 << " ";
        }
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (j - i < n / 2) {
          cout << 1 << " ";
        } else if (j - i == n / 2) {
          cout << 0 << " ";
        } else {
          cout << -1 << " ";
        }
      }
    }
  }
  cout << '\n';
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
