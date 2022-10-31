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

const int N = 1e5 + 5;

bool p[N];
vector < int > primes;

void init () {
  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      primes.emplace_back(i);
      for (int j = i + i; j < N; j += i) {
        p[j] = 1;
      }
    }
  }
}

void test_case() {
  int d; cin >> d;
  int ans = *lower_bound(all(primes), d + 1);
  ans *= *lower_bound(all(primes), ans + d);
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}