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
// using t3 = tuple < int, int, int >;
using t3 = array < int, 3 >;

void test_case() {
  int n; cin >> n;
  t3 minX = {(int)2e9, 0, 0};
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    t3 X = {x + y, x, y};
    minX = min(minX, X);
  }
  t3 maxA = {-(int)2e9, 0, 0};
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    t3 A = {x + y, x, y};
    maxA = max(maxA, A);
  }
  int tx = minX[1] + maxA[1];
  int ty = minX[2] + maxA[2];
  cout << tx << " " << ty << '\n';
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
