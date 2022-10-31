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

int main () {
  int n; scanf("%d", &n);
  int mx = -1, g = 0;
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    mx = max(mx, x);
    g = gcd(x, g);
  }
  int req = mx / g - n;
  req & 1 ? puts("Alice") : puts("Bob");
  return 0;
}