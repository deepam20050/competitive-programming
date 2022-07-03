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

const int M = 1e4 + 5;

lli cube[M];

void init () {
  cube[0] = -1;
  for (int i = 1; i < M; ++i) {
    cube[i] = i * 1ll * i * i;
  }
}

void test_case() {
  lli x; cin >> x;
  for (int i = 1; 1ll * i * i * i <= x; ++i) {
    if (binary_search(cube, cube + M, x - 1ll * i * i * i)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
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