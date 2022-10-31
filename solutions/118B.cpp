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
  int m = 2 * n + 1;
  vector < vector < int > > a(m, vector < int > (m, -1));  
  int curr = 0;
  int add = 1;
  for (int i = 0; i < m; ++i) {
    a[i][n] = curr;
    for (int k = n + 1; k < m; ++k) {
      a[i][k] = a[i][k - 1] - 1;
    }
    for (int k = n - 1; k >= 0; --k) {
      a[i][k] = a[i][k + 1] - 1;
    }
    curr += add;
    if (curr == n + 1) {
      curr = n - 1;
      add = -1; 
    }
  }
  vector < string > ans(m, string(m, '!'));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] >= 0) {
        ans[i][j] = a[i][j] + '0';
      } else {
        ans[i][j] = ' ';
      }
    }
    while (!ans[i].empty() && ans[i].back() == ' ') {
      ans[i].pop_back();
    }
  }
  for (auto &s : ans) {
    for (int j = 0; j < sz(s); ++j) {
      cout << s[j];
      if (j < sz(s) - 1) {
        cout << " ";
      } else {
        cout << '\n';
      }
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