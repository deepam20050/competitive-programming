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

const int N = 1e5 + 5;
const int M = 26;

int p[N][M];

void test_case() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < M; ++j) {
      p[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < M; ++j) {
      p[i][j] = p[i - 1][j];
    }
    ++p[i][s[i - 1] - 'a'];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i + 1, r = n - i;
    ans += p[r][s[i] - 'a'] - p[l - 1][s[i] - 'a'] == r - l + 1;
  }
  cout << ans << '\n';
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