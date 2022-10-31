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
  array < lli, 2 > s{};
  vector < int > a(n);
  vector < int > ans(n, 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    s[i & 1] += a[i];
  } 
  if (s[0] > s[1]) {
    for (int i = 0; i < n; i += 2) {
      ans[i] = a[i];
    }
  } else {
    for (int i = 1; i < n; i += 2) {
      ans[i] = a[i];
    }
  }
  for (auto &e : ans) {
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
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}