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

string s[5];
int n, m;

inline bool check (int x, int y) {
  return 0 <= x && x < n && 0 <= y && y < m;
}

void test_case() {
  cin >> n >> m;
  vector < pii > robots;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'R') {
        robots.emplace_back(i, j);
      }
    }
  }
  for (auto [x, y] : robots) {
    int dx = -x, dy = -y;
    bool ok = 1;
    for (auto [x0, y0] : robots) {
      ok &= check(x0 + dx, y0 + dy);
    }
    if (ok) {
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