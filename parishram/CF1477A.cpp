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

const int N = 2e5 + 5;

lli arr[N];

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    lli k;
    scanf("%d %lld", &n, &k);
    FOR(i, 0, n) {
      scanf("%lld", arr + i);
    }
    k -= arr[0];
    lli g = 0;
    FOR(i, 0, n) {
      g = __gcd(g, arr[i] - arr[0]);
    }
    k % g ? puts("NO") : puts("YES");
  }
  return 0;
}
