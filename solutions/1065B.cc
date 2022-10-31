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
  lli n, m; cin >> n >> m;
  lli curr = 1, rem = m;
  while (rem > 0) {
    lli add = min(curr, rem);
    ++curr;
    rem -= add;
  }
  if (curr == 1) {
    curr = n;
  } else {
    curr = n - curr;
  }
  cout << max(0ll, n - 2 * m) << " " << curr << '\n';
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