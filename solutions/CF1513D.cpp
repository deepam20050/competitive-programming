#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

int a[N];
pair < int, int > pr[N];
bitset < N > vis;
int n, p;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    vis.reset();
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      pr[i] = {a[i], i};
    }
    sort(pr, pr + n);
    auto ans = 0ll;
    for (int i = 0; i < n; ++i) {
      int x = pr[i].first, pos = pr[i].second;
      if (x >= p) break;
      while (pos > 0 && !vis[pos - 1] && a[pos - 1] % x == 0) {
        vis[pos - 1] = 1;
        ans += x;
        --pos;
      }
      pos = pr[i].second;
      while (pos < n - 1 && !vis[pos] && a[pos + 1] % x == 0) {
        vis[pos] = 1;
        ans += x;
        ++pos;
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      ans += !vis[i] * p;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
