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
  vector < vector < int > > arr(n + 1, vector < int > (n, 0));
  for (auto &e : arr[0]) {
    cin >> e;
  }
  for (int i = 1; i <= n; ++i) {
    vector < int > cnt(n + 1);
    for (auto &e : arr[i - 1]) {
      ++cnt[e];
    }
    for (int j = 0; j < n; ++j) {
      arr[i][j] = cnt[arr[i - 1][j]];
    }
  }
  int nq; cin >> nq;
  while (nq--) {
    int x, k; cin >> x >> k;
    k = min(k, n);
    --x;
    cout << arr[k][x] << '\n';
  }
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
