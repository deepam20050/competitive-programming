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

int main () {
  int n, s;
  scanf("%d %d", &n, &s);
  vector < int > indeg(n + 1);
  FOR(i, 1, n) {
    int x, y;
    scanf("%d %d", &x, &y);
    ++indeg[x];
    ++indeg[y];
  }
  int l = 0;
  for (auto &e : indeg) {
    l += e == 1;
  }
  printf("%.9lf\n", (s + s) / (1.0 * l));
  return 0;
}
