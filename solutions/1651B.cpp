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

const int limit = 1e9;

void test_case() {
  int n; cin >> n;
  vector < int > a(n);
  a[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (3 * a[i - 1] > limit) {
      cout << "NO\n";
      return;
    }
    a[i] = 3 * a[i - 1];
  }
  cout << "YES\n";
  for (auto &e : a) {
    cout << e <<  " ";
  }
  cout << '\n';
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