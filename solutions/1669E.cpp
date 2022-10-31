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

const int N = 1e5 + 5;

string s[N];

void test_case() {
  int n; cin >> n;
  map < string, int > cnt;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    ++cnt[s[i]];
  }
  lli ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int idx = 0; idx < sz(s[i]); ++idx) {
      string t = s[i];
      for (char j = 'a'; j <= 'k'; ++j) {
        if (s[i][idx] == j) continue;
        t[idx] = j;
        ans += cnt[t];
      }
    }
  }
  cout << ans / 2 << '\n';
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