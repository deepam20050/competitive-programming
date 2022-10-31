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

using lli = int64_t;
using pii = pair < int, int >;

const int N = 2e5 + 5;

string s;
int n, m;
int pref[6][N];

void test_case() {
  cin >> n >> m;
  cin >> s;
  s = " " + s;
  string t = "abc";
  int idx = 0;
  do {
    for (int j = 1; j <= n; ++j) {
      pref[idx][j] = pref[idx][j - 1] + (s[j] != t[(j - 1) % 3]);
    }
    ++idx;
  } while (next_permutation(all(t)));
  while (m--) {
    int l, r; cin >> l >> r;
    int ans = 1e9;
    for (int i = 0; i < 6; ++i) {
      ans = min(ans, pref[i][r] - pref[i][l - 1]);
    }
    cout << ans << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}