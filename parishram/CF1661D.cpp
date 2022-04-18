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

lli b[N], closed[N];

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    scanf("%lld", b + i);
  }
  lli sum = 0, cnt = 0, ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    sum -= cnt;
    cnt -= closed[i];
    b[i] -= sum;
    if (b[i] <= 0) {
      continue;
    }
    int len = min(i + 1, k);
    lli req = (b[i] + len - 1) / len;
    ans += req;
    sum += req * 1ll * len;
    cnt += req;
    if (i - len >= 0) {
      closed[i - len] += req;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
