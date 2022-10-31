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
  int n, s; cin >> n >> s;
  if (2 * n > s) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector < int > a(n, 2);
  s -= 2 * n;
  a[0] += s;
  for (auto &e : a) {
    cout << e << " ";
  }
  cout << '\n' << 1 << '\n';
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