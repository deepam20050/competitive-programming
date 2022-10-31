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

const string p = "2357";

bool check (int x) {
  for (int i = 2; i * i <= x; ++i ){
    if (x % i == 0) {
      return 1;
    }
  }
  return 0;
}

void test_case() {
  int n; cin >> n;
  string s; cin >> s;
  for (auto &e : s) {
    if (find(all(p), e) == p.end()) {
      cout << 1 << '\n' << e << '\n';
      return;
    }
  }
  cout << 2 << '\n';
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int x = (s[i] - '0') * 10 + s[j] - '0';
      if (check(x)) {
        cout << x << '\n';
        return;
      }
    }
  }
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