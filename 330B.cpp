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

const int N = 1002;

vector < pii > ans;
set < int > g[N];
bool used[N];

void test_case() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        g[i].emplace(j);
      }
    }
  }
  for (int j = 0; j < m; ++j) {
    int x, y; cin >> x >> y;
    --x;
    --y;
    g[x].erase(y);
    g[y].erase(x);
  }
  for (int i = 0; i < n; ++i) {
    if (sz(g[i]) == n - 1) {
      cout << n - 1 << '\n';
      for (auto &to : g[i]) {
        cout << i + 1 << " " << to + 1 << '\n';
      }
      break;
    }
  }
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