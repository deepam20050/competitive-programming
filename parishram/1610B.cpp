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
  auto check = [&] (int x) {
    vector < int > b;
    for (auto &e : a) {
      if (e != x) {
        b.emplace_back(e);
      }
    }
    for (int i = 0; i < sz(b); ++i) {
      if (b[i] != b[sz(b) - i - 1]) {
        return 0;
      }
    }
    return 1;
  };
  for (int i = 0; i < n; ++i) {
    if (a[i] != a[n - i - 1]) {
      if (check(a[i]) || check(a[n - i - 1])) {
        cout << "YES\n";
        return;
      } else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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