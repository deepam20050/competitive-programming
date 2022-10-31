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

lli a, b;

int solve (int what) {
  lli d = 1;
  int ans = 0, curr = 0;
  while (what <= b / d) {
    d *= what;
    ++curr;
    lli x = b - b % d;
    if (x >= a) {
      ans = curr;
    }
  }
  return ans;
}

void test_case() {
  cin >> a >> b;
  cout << min(solve(5), solve(2)) << '\n';
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