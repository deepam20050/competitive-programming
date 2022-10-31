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
  lli a, b; cin >> a >> b;
  if (a < b) swap(a, b);
  if (a == b) {
    cout << "0 0\n";
  } else {
    lli k = a - b;
    lli moves = (-b % k + k) % k;
    lli moves2 = b % k;
    if (b - moves2 < 0) {
      moves2 = 1ll << 63;
    }
    cout << k << " " << min(moves2, moves) << '\n';
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