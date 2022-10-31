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

int a[N];
int n, nq;
int when[N];

void test_case() {
  cin >> n >> nq;
  lli sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  int complete_idx = -1, complete_val = 0;
  for (int j = 1; j <= nq; ++j) {
    int op; cin >> op;
    if (op == 1) {
      int i, x; cin >> i >> x;
      if (when[i] > complete_idx) {
        sum -= a[i];
        a[i] = x;
        sum += a[i];
        when[i] = j;
      } else {
        sum -= complete_val;
        a[i] = x;
        sum += a[i];
        when[i] = j;
      }
    } else {
      int x; cin >> x;
      complete_val = x;
      complete_idx = j;
      sum = n * 1ll * x;
    }
    cout << sum << '\n';
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