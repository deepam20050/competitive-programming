// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

int main () {
  int n;
  scanf("%d", &n);
  lli ans = 0;
  FOR(i, 2, n + 1) {
    for (int j = i + i; j <= n; j += i) {
      ans += (j / i) * 4;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
