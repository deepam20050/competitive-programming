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
  int pos = 0, neg = 0;
  vector < int > a;
  for (int i = 0; i < n; ++i) {
    int e; cin >> e;
    pos += e > 0;
    neg += e < 0;
    if (e != 0) {
      a.emplace_back(e);
    } else {
      if (a.empty()) {
        a.emplace_back(e);
      } else if (a.back() != 0) {
        a.emplace_back(e);
      }
    }
  }
  if (pos > 2 || neg > 2) {
    cout << "NO\n";
    return;
  }
  debug(a);
  auto v = a;
  sort(all(v));
  for (int i = 0; i < sz(a); ++i) {
    for (int j = i + 1; j < sz(a); ++j) {
      for (int k = j + 1; k < sz(a); ++k) {
        int x = a[i] + a[j] + a[k];
        if (!binary_search(all(v), x)) {
          cout << "NO\n";
          return;
        }
      }
    }
  }
  cout << "YES\n";
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