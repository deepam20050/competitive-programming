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
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
  }
  sort(all(a));
  vector < lli > pref(n + 1);
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + a[i - 1];
  }
  for (int k = 1; k + k + 1 <= n; ++k) {
    if (pref[k + 1] < pref[n] - pref[n - k]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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