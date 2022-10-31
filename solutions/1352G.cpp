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
  if (n < 4) {
    cout << -1 << '\n';
    return;
  }
  for (int i = n; i >= 1; --i) {
    if (i & 1) {
      cout << i << " ";
    }
  }
  cout << "4 2 ";
  for (int i = 6; i <= n; i += 2) {
    cout << i << " ";
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
};