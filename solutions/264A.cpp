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
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'r') {
      cout << i + 1 << '\n';
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'l') {
      cout << i + 1 << '\n';
    }
  }
}

int main() {
  #ifdef DEBUG
  freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
