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
  int n1 = n - (k - 1);
  if (n1 > 0 && n1 % 2 == 1) {
    cout << "YES\n";
    for (int i = 0; i < k - 1; ++i) {
      cout << 1 << " ";
    }
    cout << n1 << '\n';
    return;
  }
  int n2 = n - 2 * (k - 1);
  if (n2 > 0 && n2 % 2 == 0) {
    cout << "YES\n";
    for (int i = 0; i < k - 1; ++i) {
      cout << 2 << " ";
    }
    cout << n2 << '\n';
    return;
  }
  cout << "NO\n";
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