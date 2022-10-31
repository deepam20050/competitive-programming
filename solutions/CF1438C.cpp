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
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    FOR(i, 0, n) {
      FOR(j, 0, m) {
        int x;
        scanf("%d", &x);
        x += (x & 1) != ((i + j) & 1);
        printf("%d%c", x, " \n"[j == m - 1]);
      }
    }
  }
  return 0;
}
