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

const int N = 2e9 + 5;

vector < int > odd;

void test_case() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 3; i * i <= n + n - 1; i += 2) {
    ++ans;
  }
  cout << ans << '\n';
}

int main() {
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  cin.tie(nullptr)->sync_with_stdio(false);
  for (int i = 1; i * 1ll * i <= N; i += 2) {
    odd.emplace_back(i * i);
  }
  int nt = 1;
  cin >> nt;
  while (nt--) {
    test_case();
  }
  return 0;
}