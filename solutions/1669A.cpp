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

const string s = "Division ";

void test_case() {
  int x; cin >> x;
  if (1900 <= x) {
    cout << s << 1 << '\n';
  } else if (1600 <= x) {
    cout << s << 2 << '\n';
  } else if (1400 <= x) {
    cout << s << 3 << '\n';
  } else {
    cout << s << 4 << '\n';
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