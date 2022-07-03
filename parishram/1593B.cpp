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

const string endings[] = {"00", "25", "50", "75"};

int get (string s, string t) {
  int idx = sz(s) - 1;
  int ans = 0;
  while(idx >= 0 && s[idx] != t[1]) {
    --idx;
    ++ans;
  }
  --idx;
  while (idx >= 0 && s[idx] != t[0]) {
    --idx;
    ++ans;
  }
  return idx < 0 ? 1 << 20 : ans;
}

void test_case() {
  string s; cin >> s;
  int ans = 1 << 20;
  for (int i = 0; i < 4; ++i) {
    ans = min(ans, get(s, endings[i]));
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