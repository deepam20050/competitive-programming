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
  vector < int > a(n), b(n);
  for (auto &e : a) {
    cin >> e;
  }
  int s = 0;
  for (auto &e : b) {
    cin >> e;
    s += e;
  }
  for (int i = 0; i < n; ++i) {
    a[i] = a[i] - b[i];
  }
  sort(all(a));
  for (int i = 0; i < k; ++i) {
    s += a[i];
  }
  while (k < n && a[k] < 0) {
    s += a[k++];
  }
  cout << s << '\n';
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
