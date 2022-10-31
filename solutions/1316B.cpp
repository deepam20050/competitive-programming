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
  string s; cin >> s;
  pair < string, int > ans = {string(n, 'z'), n + 1};
  for (int i = 1; i <= n; ++i) {
    string t;
    for (int j = 0; j + 1 < i; ++j) {
      t += s[j];
    }
    string x = s.substr(i - 1);
    if (!((n - i + 1) & 1)) {
      x += t;
    } else {
      reverse(all(t));
      x += t;
    }
    ans = min(ans, make_pair(x, i));
  }
  cout << ans.first << '\n' << ans.second << '\n';
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
