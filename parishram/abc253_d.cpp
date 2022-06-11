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

typedef long long int64;
typedef pair < int, int > pii;

int64 calc (int64 n, int64 x) {
  int64 k = n / x;
  return x * k * (k + 1) >> 1ll;
}

void test_case() {
  int64 n, a, b; cin >> n >> a >> b;
  int64 ans = n * (n + 1) >> 1ll;
  ans -= calc(n, a) + calc(n, b) - calc(n, lcm(a, b));
  cout << ans << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}