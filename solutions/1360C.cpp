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
  int cnt[2] = {};
  for (auto &e : a) {
    cin >> e;
    ++cnt[e & 1];
  }
  if (cnt[0] % 2 != cnt[1] % 2) {
    cout << "NO\n";
    return;
  }
  if (cnt[0] % 2 == 0) {
    cout << "YES\n";
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (abs(a[i] - a[j]) == 1) {
        cout << "YES\n";
        return;
      }
    }
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