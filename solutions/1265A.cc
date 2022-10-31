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
  string s; cin >> s;
  int n = sz(s);
  for (int i = 1; i < n; ++i) {
    if (s[i] != '?' && s[i] != '?' && s[i] == s[i - 1]) {
      cout << -1 << '\n';
      return;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] != '?') continue;
    if (i == 0) {
      if (n == 1) {
        s[i] = 'a';
        break;
      }
      for (char c = 'a'; c <= 'c'; ++c) {
        if (c != s[i + 1]) {
          s[i] = c;
          break;
        }
      }
    } else {
      for (char c = 'a'; c <= 'c'; ++c) {
        if (s[i - 1] != c) {
          if ((i + 1 == n) || (i + 1 < n && s[i + 1] != c)) {
            s[i] = c;
            break;
          }
        }
      }
    }
  }
  cout << s << '\n';
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