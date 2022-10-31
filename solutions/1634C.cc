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
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
      cout << i << '\n';
    }
    return;
  } else if (n & 1) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  int val = 1;
  while (val < n * k) {
    for (int j = 0; j < k; ++j) {
      cout << val << " ";
      val += 2;
    }
    cout << '\n';
  }
  val = 2;
  while (val < n * k) {
    for (int j = 0; j < k; ++j) {
      cout << val << " ";
      val += 2;
    }
    cout << '\n';
  }
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