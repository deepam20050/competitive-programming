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
  memset(cnt, 0, sizeof cnt);
  string s, t; cin >> s >> t;
  sort(all(s));
  if (t[0] != 'a') {
    cout << s << '\n';
  } else if (s[0] != t[0]) {
    cout << s << '\n';
  } else {
    for (auto &e : s) {
      ++cnt[e - 'a'];
    }
    swap(t[1], t[2]);
    for (auto &e : t) {
      cout << string(cnt[e - 'a'], e);
    }
    for (int i = 3; i < 26; ++i) {
      cout << string(cnt[i], i + 'a');
    }
    cout << '\n';
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