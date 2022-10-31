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

const int N = 1005;

int up[N];
int down[N];
string s[N];
int pref[N];
int suff[N];
int n, m;

void test_case() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    up[i] = n + 1;
    down[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] = " " + s[i];
    for (int j = 1; j <= m; ++j) {
      if (s[i][j] == 'B') {
        up[j] = min(up[j], i);
        down[j] = max(down[j], i);
      }
    }
  }
  int ans = 2e9;
  int ansx, ansy;
  for (int i = 1; i <= n; ++i) {
    pref[0] = -2e9;
    suff[m + 1] = -2e9;
    for (int j = 1; j <= m; ++j) {
      int best = -2e9;
      if (up[j] != n + 1) {
        best = max(best, (int)abs(up[j] - i));
      }
      if (down[j] != -1) {
        best = max(best, (int)abs(down[j] - i));
      }
      pref[j] = max(pref[j - 1], -j + best);
    }
    for (int j = m; j >= 1; --j) {
      int best = -2e9;
      if (up[j] != n + 1) {
        best = max(best, (int)abs(up[j] - i));
      }
      if (down[j] != -1) {
        best = max(best, (int)abs(down[j] - i));
      }
      suff[j] = max(suff[j + 1], j + best);
    }
    for (int j = 1; j <= m; ++j) {
      int tmp = max(pref[j] + j, suff[j] - j);
      if (tmp >= 0 && ans > tmp) {
        ans = tmp;
        ansx = i;
        ansy = j;
      }
    }
  }
  cout << ansx << " " << ansy << '\n';
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