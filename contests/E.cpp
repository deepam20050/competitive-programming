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
  vector < pii > a(n);
  vector < int > deg(n);
  for (auto &[x, y] : a) {
    cin >> x >> y;
    --x;
    --y;
    ++deg[x];
    ++deg[y];
  }
  for (auto &e : deg) {
    if (e != 2) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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