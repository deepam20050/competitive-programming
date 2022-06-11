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

const int N = 5005;

int pref[N];
string s;

void test_case() {
  cin >> s;
  int n = sz(s);
  s = " " + s;
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] + (s[i] == 'b');
  }
  int ans = n - pref[n];
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; ++j) {
      int tmp = pref[i - 1] + (j - i + 1 - (pref[j] - pref[i - 1])) + pref[n] - pref[j];
      ans = max(ans, n - tmp);
    }
  }
  cout << ans << '\n';
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