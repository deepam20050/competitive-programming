#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 3e5 + 5;

int lft[N], rgt[N], arr[N];

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    memset(lft, 0, sizeof lft);
    memset(rgt, 0, sizeof rgt);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", arr + i);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
      memset(rgt, 0, sizeof rgt);
      for (int j = n; j > i; --j) {
        ans += 1LL * lft[arr[j]] * rgt[arr[i]];
        ++rgt[arr[j]];
      }
      ++lft[arr[i]];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
