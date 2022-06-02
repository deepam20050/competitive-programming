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
  vector < int > v(n);
  FOR(i, 1, n) {
    int x, y; scanf("%d %d", &x, &y);
    --x; --y;
    ++v[x]; ++v[y];
  }
  find(all(v), 2) != v.end() ? puts("NO") : puts("YES");
  return 0;
}