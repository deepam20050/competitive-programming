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
  int n, r, b; cin >> n >> r >> b;
  int p = r / (b + 1), q = r % (b + 1);
  for (int i = 0; i < q; ++i) {
    cout << string(p + 1, 'R') + "B";
  }
  for (int i = q; i < b; ++i) {
    cout << string(p, 'R') + "B";
  }
  cout << string(p, 'R') << '\n';
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