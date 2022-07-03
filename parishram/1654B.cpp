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

int cnt[26];

void test_case() {
  string s; cin >> s;
  memset(cnt, 0, sizeof cnt);
  int n = sz(s);
  s = " " + s;
  for (int i = n; i >= 1; --i) {
    ++cnt[s[i] - 'a'];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[s[i] - 'a'] == 1) {
      cout << s.substr(i, n) << '\n';
      return;
    }
    --cnt[s[i] - 'a'];
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