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

const int N = 2e5 + 5;

int n;
int a[N];
int lft[N], rgt[N];

void test_case() {
  cin >> n;
  for (int i = 0; i <= n + 1; ++i) {
    lft[i] = rgt[i] = -1;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; --i) {
    rgt[i] = rgt[i + 1];
    if (rgt[i] == -1 && a[i] == a[i + 1]) {
      rgt[i] = i;
    }
  }
  for (int i = 2; i <= n; ++i) {
    lft[i] = lft[i - 1];
    if (lft[i] == -1 && a[i] == a[i - 1]) {
      lft[i] = i - 1;
    }
  }
  if (lft[n] == rgt[1]) {
    cout << 0 << '\n';
    return;
  }
  int ans = 1e9;
  for (int i = 1; i <= n - 1; ++i) {
    int j1 = lft[i - 1] + 1;
    int j2 = rgt[i + 2] + 1;
    int curr = 1;
    if (j1 > 0) {
      curr += i - j1;
    }
    if (j2 > 0) {
      curr += j2 - i;
    }
    ans = min(ans, curr);
  }
  cout << ans << '\n';
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