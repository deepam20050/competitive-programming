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

string s[50];
bool row[50];
bool col[50];

void test_case() {
  int n, m, r, c; cin >> n >> m >> r >> c;
  --r; --c;
  memset(row, 0, sizeof row);
  memset(col, 0, sizeof col);
  bool black = 0;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      row[i] |= s[i][j] == 'B';
      col[j] |= s[i][j] == 'B';
      black |= s[i][j] == 'B';
    }
  }
  if (s[r][c] == 'B') {
    cout << 0 << '\n';
  } else if (row[r] || col[c]) {
    cout << 1 << '\n';
  } else if (black) {
    cout << 2 << '\n';
  } else {
    cout << -1 << '\n';
  }
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