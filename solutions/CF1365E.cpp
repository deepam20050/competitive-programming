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

const int N = 505;

lli arr[N];
int n;

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) scanf("%lld", arr + i);
  lli ans = 0;
  FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, n) {
    ans = max(ans, arr[i] | arr[j] | arr[k]);
  }
  printf("%lld\n", ans);
  return 0;
}