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

typedef long long lli;
typedef pair < int, int > pii;
typedef unsigned int uint;

const int N = 2e5 + 5;

int n, k;
int a[N];

void test_case() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int j = 30; j >= 0; --j) {
    int off = n;
    for (int i = 0; i < n; ++i) {
      off -= a[i] >> j & 1;
    }
    if (k >= off) {
      k -= off;
      for (int i = 0; i < n; ++i) {
        a[i] |= 1 << j;
      }
    }
  }
  uint ans = (1u << 31) - 1;
  for (int i = 0; i < n; ++i) {
    ans &= a[i];
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