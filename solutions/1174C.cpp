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
  int n; cin >> n;
  vector < bool > not_prime(n + 1);
  vector < int > ans(n + 1);
  int color = 0;
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      ++color;
      for (int j = i; j <= n; j += i) {
        not_prime[j] = 1;
        ans[j] = color;
      }
    }
  }
  for (int i = 2; i <= n; ++i) {
    cout << ans[i] << " ";
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
