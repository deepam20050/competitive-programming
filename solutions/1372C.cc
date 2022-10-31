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
    --e;
  }
  if (is_sorted(all(a))) {
    cout << 0;
  } else {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += a[i] == i;
    }
    for (int i = 0; i < n && a[i] == i; --cnt, ++i);
    for (int i = n - 1; i >= 0 && a[i] == i; --cnt, --i);
    cnt ? cout << 2 : cout << 1;
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