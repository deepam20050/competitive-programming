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

int n, x, y;

void test_case() {
  cin >> n >> x >> y;
  vector < lli > blue(n + 1);
  vector < lli > red(n + 1);
  red[n] = 1;
  for (int i = n; i >= 2; --i) {
    red[i - 1] += red[i];
    blue[i] += red[i] * x;
    red[i - 1] += blue[i];
    blue[i - 1] += blue[i] * y;
  }
  cout << blue[1] << '\n';
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
