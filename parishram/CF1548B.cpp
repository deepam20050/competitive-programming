// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;
const int LN = 19;

lli a[N];
lli arr[N];

struct SparseTable {
  lli st[LN][N];
  void build (int n) {
    for (int i = 1; i <= n; ++i) {
      st[0][i] = a[i];
    }
    for (int i = 1; i < LN; ++i) {
      for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
        st[i][j] = __gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
  }
  lli query (int l, int r) {
    int t = __lg(r - l + 1);
    return __gcd(st[t][l], st[t][r - (1 << t) + 1]);
  }
} st1;

int n;

bool f (int k) {
  for (int i = 1; i + k - 1 < n; ++i) {
    int l = i, r = i + k - 1;
    if (st1.query(l, r) > 1) {
      return 1;
    }
  }
  return 0;
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%lld", arr + i);
  }
  FOR(i, 1, n) {
    a[i] = abs(arr[i] - arr[i + 1]);
  }
  st1.build(n - 1);
  int l = 2, r = N;
  int ans = 1;
  FOR(i, 0, 20) {
    int m = l + r >> 1;
    if (f(m - 1)) {
      ans = m;
      l = m;
    } else {
      r = m;
    }
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
