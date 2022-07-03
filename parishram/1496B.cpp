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
  int n, k; cin >> n >> k;
  set < int > s;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    s.emplace(x);
  }
  int mex = 0, max = *s.rbegin();
  while (s.count(mex) > 0) {
    ++mex;
  } 
  if (mex == sz(s)) {
    cout << sz(s) + k << '\n';
  } else {
    cout << sz(s) + (k > 0 && s.count((mex + max + 1) / 2) == 0) << '\n';
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