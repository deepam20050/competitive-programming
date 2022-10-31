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
  if (n * 1ll * (n + 1) % 4) {
    cout << "NO\n";
    return;
  }
  vector < int > a(n);
  iota(all(a), 1);
  rotate(a.begin(), a.begin() + n / 4, a.end());
  cout << "YES\n";
  for (int i = 0; i + i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << '\n';
  for (int i = n / 2; i < n; ++i) {
    cout << a[i] << " \n"[i == n - 1];
  }
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