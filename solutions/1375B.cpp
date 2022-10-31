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

const int N = 301;

int a[N][N];
int n, m;

void test_case() {
  cin >> n >> m;
  bool ok = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
      ok &= a[i][j] < 5;
      if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
        ok &= a[i][j] <= 2;
        a[i][j] = 2;
      } else if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
        ok &= a[i][j] <= 3;
        a[i][j] = 3;
      } else {
        a[i][j] = 4;
      }
    }
  } 
  if (!ok) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << " \n"[j == m - 1];
    }
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