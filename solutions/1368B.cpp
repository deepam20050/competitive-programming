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

const string str = "codeforces";

void test_case() {
  lli k; cin >> k;
  multiset < int > s;
  for (int i = 0; i < 10; ++i) {
    s.emplace(1);
  }
  lli curr = 1;
  while (curr < k) {
    int x = *s.begin();
    s.erase(s.begin());
    s.emplace(x + 1);
    curr /= x;
    curr *= x + 1;
  }
  int idx = 0;
  for (int x : s) {
    cout << string(x, str[idx++]);
  }
  cout << '\n';
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