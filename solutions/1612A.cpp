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

bool check (int a, int b, int x, int y) {
  return 2 * (abs(a - x) + abs(b - y)) == x + y;
}

void test_case() {
  int x, y; cin >> x >> y;
  int ansx = -1, ansy = -1;
  if (!(x + y & 1)) { 
    ansx = x + y >> 1;
    ansy = 0;
    if (!check(ansx, ansy, x, y)) {
      swap(ansx, ansy);
    }
  }
  cout << ansx << " " << ansy << '\n';
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