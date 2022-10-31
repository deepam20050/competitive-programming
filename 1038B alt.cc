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
  if (n <= 2) {
    cout << "No\n";
    return;
  }
  int k = n & 1 ? (n + 1) / 2 : n / 2;
  cout << "Yes\n1 " << k << '\n';
  cout << n - 1 << " ";
  for (int i = 1; i <= n; ++i) {
    if (i != k) {
      cout << i << " ";
    }
  }
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