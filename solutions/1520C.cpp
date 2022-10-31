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

const int N = 105;

int a[N][N];

void test_case() {
  int n; cin >> n;
  if (n == 2) {
    cout << "-1\n";
    return;
  }
  int curr = 1;
  for (int i = 0; i < n; ++i) {
    a[i][i] = curr++;
  }
  for (int i = 1, j = 1, op = 0; curr <= n * n; op ^= 1) {
    if (op) {
      int x = 0, y = j;
      while (x < n && y < n) {
        a[x][y] = curr++;
        ++x;
        ++y;
      }
      ++j;
    } else {
      int x = i, y = 0;
      while (x < n && y < n) {
        a[x][y] = curr++;
        ++x;
        ++y;
      }
      ++i;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << a[i][j] << " \n"[j == n - 1];
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