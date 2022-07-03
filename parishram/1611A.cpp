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

bool check (char c) {
  return (c - '0') % 2 == 0;
}

void test_case() {
  string s; cin >> s;
  bool even = 0;
  for (auto &e : s) {
    even |= check(e);
  }
  if (check(s.back())) {
    cout << 0 << '\n';
  } else if (check(s.front())) {
    cout << 1 << '\n';
  } else {
    even ? cout << 2 << '\n' : cout << -1 << '\n';
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