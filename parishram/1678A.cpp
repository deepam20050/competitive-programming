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

const int N = 105;

int cnt[N];

void test_case() {
  int n; cin >> n;
  memset(cnt, 0, sizeof cnt);
  vector < int > a(n);
  for (auto &e : a) {
    cin >> e;
    ++cnt[e];
  }
  if (cnt[0]) {
    cout << n - cnt[0] << '\n';
  } else {
    for (int i = 0; i < N; ++i) {
      if (cnt[i] > 1) {
        cout << n - 1 + 1 << '\n';
        return;
      }
    }
    cout << n + 1 << '\n';
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