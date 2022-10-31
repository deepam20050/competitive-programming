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
  int ans = 0, ans2 = 0;
  char prev = '$';
  for (int i = 0; i < n; i += 2) {
    ans += s[i] != s[i + 1];
    if (s[i] == s[i + 1]) {
      if (prev != s[i]) ++ans2;
      prev = s[i];
    }
  }
  cout << ans << " " << max(1, ans2) << '\n';
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