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
  int x, y; scanf("%d %d", &x, &y);
  int a[] = {y, y, y};
  int turns = 0;
  while (1) {
    if (a[0] >= x && a[1] >= x && a[2] >= x) {
      printf("%d\n", turns);
      exit(0);
    }
    ++turns;
    int r = turns % 3;
    int c = 0;
    FOR(i, 0, 3) {
      if (i != r) c += a[i];
    }
    --c;
    a[r] = c;
  }
  return 0;
}