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

map < char, char > win;

void test_case() {
  int n; array < int, 3 > a; cin >> n >> a[0] >> a[1] >> a[2];
  string s; cin >> s;
  string ans(n, 'X');
  // R, P, S
  // a[0], a[1], a[2]
  int idx = 0;
  int yes = 0;
  for (const char x : "RPS") {
    for (int i = 0; i < n; ++i) {
      if (s[i] == win[x] && a[idx] > 0) {
        ans[i] = x;
        --a[idx];
        ++yes;
      }
    }
    ++idx;
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] != 'X') continue;
    if (a[0]) {
      ans[i] = 'R';
      --a[0];
    } else if (a[1]) {
      ans[i] = 'P';
      --a[1];
    } else if (a[2]) {
      ans[i] = 'S';
      --a[2];
    }
  }
  if (yes < (n + 1) / 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << ans << '\n';
  }
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  win['R'] = 'S';
  win['P'] = 'R';
  win['S'] = 'P';
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}
