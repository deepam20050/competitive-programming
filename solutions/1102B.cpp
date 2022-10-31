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

const int N = 5005;

int n, k;
int a[N];
pii p[N];
int ans[N];
vector < int > who[N];

void test_case() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    p[i] = {x, i};
  }
  sort(p, p + n);
  for (int i = 0; i < n; ++i) {
    auto [val, idx] = p[i];
    who[i % k].emplace_back(val);
    ans[idx] = i % k + 1;
  }
  for (int i = 0; i < k; ++i) {
    for (int j = 1; j < sz(who[i]); ++j) {
      if (who[i][j] == who[i][j - 1]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
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