#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int n, m;
int a[N], p[N];
map < int, int > cnt;

int main () {
  scanf("%d %d", &n, &m);
  int idx;
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    p[i] = p[i - 1] + (a[i] < m);
    if (a[i] == m) {
      idx = i;
    }
  }
  FOR(i, idx, n + 1) {
    int x = p[i] - p[idx];
    int y = i - idx - x;
    ++cnt[y - x];
  }
  lli ans = 0;
  FOR(i, 1, idx + 1) {
    int x = p[idx - 1] - p[i - 1];
    int y = idx - i - x;
    ans += cnt[x - y];
    ans += cnt[x - y + 1];
  }
  printf("%lld\n", ans);
  return 0;
}
