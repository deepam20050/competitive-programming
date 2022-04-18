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

const int LN = 11;
const int N = 2e5 + 5;

unordered_map < int, int > freq[LN];
int a[N];

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    a[i] = x;
    x %= k;
    for (int pw = 10, i = 1; i < LN; pw = 10ll * pw % k, ++i) {
      ++freq[i][x * 1ll * pw % k];
    }
  }
  lli ans = 0;
  FOR(i, 0, n) {
    int x = a[i];
    int d = 0;
    int y = x;
    int pw = x % k;
    while (y > 0) {
      ++d;
      pw = 10 * 1ll * pw % k;
      y /= 10;
    }
    --freq[d][pw];
    int req = k - x % k;
    if (req == k) {
      req = 0;
    }
    ans += freq[d][req];
    ++freq[d][pw];
  }
  printf("%lld\n", ans);
  return 0;
}
