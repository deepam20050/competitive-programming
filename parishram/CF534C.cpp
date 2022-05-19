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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 1e6 + 5;
const int M = 2e5 + 5;

int d[M];

int main () {
  int n;
  lli A; scanf("%d %lld", &n, &A);
  lli sum = 0;
  FOR(i, 0, n) {
    scanf("%d", d + i);
    sum += d[i];
  }
  FOR(i, 0, n) {
    int l = max(1ll, A - (sum - d[i]));
    int r = min(1ll * d[i], A - (n - 1));
    printf("%d\n", d[i] - (r - l + 1));
  }
  return 0;
}
