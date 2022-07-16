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
  if (n % 2 == 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector < int > a(2 * n);
  for (int i = 0; i < n; ++i) {
    a[i] = 2 * i + 1;
    a[i + n] = 2 * i + 2;
    if (i & 1) {
      swap(a[i], a[i + n]);
    }
  }
  for (auto &e : a) {
    cout << e << " ";
  }
  cout << '\n';
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