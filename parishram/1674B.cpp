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

vector < string > ans;

void init () {
  int idx = 0;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) {
      if (i == j) continue;
      ans.emplace_back(string());
      ans.back() += i + 'a';
      ans.back() += j + 'a';
      ++idx;
    }
  }
  sort(all(ans));
}

void test_case() {
  string s; cin >> s;
  cout << lower_bound(all(ans), s) - ans.begin() + 1 << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}