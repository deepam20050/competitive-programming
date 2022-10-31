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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));
  a.erase(unique(all(a)), a.end());
  if (sz(a) > k) {
    cout << "-1\n";
    return;
  }
  while (sz(a) < k) {
    a.emplace_back(1);
  }
  cout << sz(a) * n << '\n';
  for (int i = 0; i < n; ++i) {
    for (auto &e : a) {
      cout << e << " ";
    }
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
}