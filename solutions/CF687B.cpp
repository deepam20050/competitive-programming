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
  int n, k;
  scanf("%d %d", &n, &k);
  lli curr = 1;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    curr = __gcd(1ll * k, lcm(curr, 1ll * x));
  }
  curr == k ? puts("Yes") : puts("No");
  return 0;
}
