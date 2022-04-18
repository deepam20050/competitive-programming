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

const int N = 1e5 + 5;

int n;
lli k;
int a[N];
map < int, int > vals;

int main () {
  scanf("%d %lld", &n, &k);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    ++vals[a[i]];
  }
  sort(a + 1, a + n + 1);
  for (auto [val, cnt] : vals) {
    if (cnt * 1ll * n < k) {
      k -= cnt * 1ll * n;
      continue;
    }
    FOR(i, 1, n + 1) {
      if (k <= cnt) {
        printf("%d %d\n", val, a[i]);
        return 0;
      }
      k -= cnt;
    }
  }
  return 0;
}
