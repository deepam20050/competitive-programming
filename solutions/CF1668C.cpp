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

const int N = 5005;

int a[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  lli ans = 2e18;
  FOR(i, 1, n + 1) {
    lli lst = 0, sum = 0;
    FOR(j, i + 1, n + 1) {
      lli c = lst / a[j] + 1ll;
      sum += c;
      lst = c * a[j];
    }
    lst = 0;
    for (int j = i - 1; j >= 1; --j) {
      lli c = lst / a[j] + 1ll;
      sum += c;
      lst = c * a[j];
    }
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}
