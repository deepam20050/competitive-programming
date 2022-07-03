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
  int d = 2e9;
  for (int i = 0; i + 1 < n; ++i) {
    d = min(d, a[i + 1] - a[i]);
  }
  int idx = 0;
  int ans = -2e9;
  for (int i = 0; i + 1 < n; ++i) {
    if (d == a[i + 1] - a[i]) {
      int val = n - 2 + (a[0] == a[i]) + (a[n - 1] == a[i + 1]);
      if (val > ans) {
        ans = val;
        idx = i;
      }
    }
  }
  cout << a[idx] << " ";
  for (int i = idx + 2; i < n; ++i) {
    cout << a[i] << " ";
  }
  for (int i = 0; i < idx; ++i) {
    cout << a[i] << " ";
  }
  cout << a[idx + 1] << '\n';
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