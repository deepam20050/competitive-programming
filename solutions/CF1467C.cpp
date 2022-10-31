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

int n[3];
int arr[3][N];
lli pref[3];

int main () {
  FOR(i, 0, 3) scanf("%d", n + i);
  lli total = 0;
  FOR(i, 0, 3) {
    FOR(j, 1, n[i] + 1) {
      scanf("%d", &arr[i][j]);
      total += arr[i][j];
      pref[i] += arr[i][j];
    }
    sort(arr[i] + 1, arr[i] + n[i] + 1);
  }
  lli ans = max({
      total - 2ll * *min_element(pref, pref + 3),
      total - 2ll * (arr[0][1] + arr[1][1]),
      total - 2ll * (arr[0][1] + arr[2][1]),
      total - 2ll * (arr[1][1] + arr[2][1])
      });
  printf("%lld\n", ans);
  return 0;
}
