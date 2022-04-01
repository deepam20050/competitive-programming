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

const int N = 2e5 + 5;

int a[N], b[N];
int x, y, k;
int pos[N];
int n, m;

void rekt () {
  puts("-1");
  exit(0);
}


lli f (int l, int r, int mx) {
  if (l > r) {
    return 0;
  }
  int p = *max_element(a + l, a + r + 1);
  bool can_del = mx > p;
  int net = r - l + 1;
  if (net < k && !can_del) {
    rekt();
  }
  int lft = net % k;
  lli sum = lft * 1ll * y;
  net -= lft * 1ll;
  if (y * 1ll * k >= 1ll * x) {
    sum += net / k * 1ll * x;
  } else if (can_del) {
    sum += net * 1ll * y;
  } else {
    sum += (net - k) * 1ll * y + 1ll * x;
  }
  return sum;
}

int main () {
  scanf("%d %d", &n, &m);
  scanf("%d %d %d", &x, &k, &y);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
    pos[a[i]] = i;
  }
  FOR(i, 1, m + 1) {
    scanf("%d", b + i);
  }
  lli ans = 0;
  ans += f(1, pos[b[1]] - 1, b[1]);
  ans += f(pos[b[m]] + 1, n, b[m]);
  FOR(i, 2, m + 1) {
    if (pos[b[i]] < pos[b[i - 1]]) {
      rekt();
    }
    int l = pos[b[i - 1]] + 1, r = pos[b[i]] - 1, mx = max(b[i], b[i - 1]);
    ans += f(l, r, mx);
  }
  printf("%lld\n", ans);
  return 0;
}
