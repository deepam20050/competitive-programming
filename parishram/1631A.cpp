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

const int N = 1e4 + 5;

int a[2][N];

void test_case() {
  int n; cin >> n;
  int mx[2] = {};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      if (mx[i] < a[i][j]) {
        mx[i] = a[i][j];
      }
    }
  }
  int idx = 0;
  if (mx[1] > mx[0]) {
    idx = 1;
  }
  debug(mx[idx])
  for (int i = 0; i < n; ++i) {
    if (a[idx][i] != mx[idx] && a[idx][i] < a[idx ^ 1][i]) {
      swap(a[idx][i], a[idx ^ 1][i]);
    }
  }
  cout << (*max_element(a[0], a[0] + n)) * 1ll * (*max_element(a[1], a[1] + n)) << '\n';
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