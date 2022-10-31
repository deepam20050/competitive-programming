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

const int N = 2e5 + 5;

int cnt[N];
int n;

lli nc3 (lli n) {
  return n * (n - 1) * (n - 2) / 6ll;
}

lli nc2 (lli n) {
  return n * (n - 1) >> 1ll;
}

void test_case() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    ++cnt[x];
  }
  lli ans = nc3(n);
  for (int i = 1; i < N; ++i) {
    if (cnt[i] >= 3) {
      ans -= nc3(cnt[i]);
    }
    if (cnt[i] >= 2) {
      ans -= nc2(cnt[i]) * (n - cnt[i]);
    }
  } 
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