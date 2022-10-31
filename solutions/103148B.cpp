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

const int N = 1e6 + 5;

int t[N];
int a[N];
int pos[N];

void update (int idx, int add) {
  while (idx < N) {
    t[idx] += add;
    idx += idx & -idx;
  }
}

int query (int idx) {
  int ret = 0;
  while (idx > 0) {
    ret += t[idx];
    idx -= idx & -idx;
  }
  return ret;
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> a[i];
    if (!pos[a[i]]) {
      pos[a[i]] = i;
    }
  }
  lli ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    if (pos[a[i]] == i) {
      update(i, 1);
    } else {
      ans += query(i) - query(pos[a[i]]);
      update(pos[a[i]], -1);
    }
  }
  cout << n + ans << '\n';
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