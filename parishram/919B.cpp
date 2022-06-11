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

const int N = 5e7 + 5;

vector < int > perfect;

void init () {
  for (int i = 19; i < N && sz(perfect) < 10000; ++i) {
    int x = i;
    int sum = 0;
    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }
    if (sum == 10) {
      perfect.emplace_back(i);
    }
  }
}

void test_case() {
  int k; cin >> k;
  cout << perfect[k - 1] << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  init();
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}