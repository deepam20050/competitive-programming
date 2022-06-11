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

bool special[26];
int n;
string s;
int k;

void test_case() {
  cin >> n;
  cin >> s;
  cin >> k;
  memset(special, 0, sizeof special);
  for (int i = 0; i < k; ++i) {
    char c; cin >> c;
    special[c - 'a'] = 1;
  }
  set < int > good, points;
  for (int i = 0; i < n; ++i) {
    points.emplace(i);
    if (special[s[i] - 'a']) {
      good.emplace(i);
    }
  }
  int ans = 0;
  while (sz(good) >= 1) {
    if (sz(good) == 1 && *points.begin() == *good.begin()) {
      break;
    }
    ++ans;
    for (auto &x : good) {
      auto it = points.find(x);
      if (it != points.begin()) {
        --it;
        int idx = *it;
        if (special[s[idx] - 'a']) {
          good.erase(idx);
        }
        points.erase(idx);
      }
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
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}