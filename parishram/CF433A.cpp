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
  int s = 0;
  int cnt[2] = {0, 0};
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    s += x;
    ++cnt[x == 100];
  }
  FOR(i, 0, cnt[0] + 1) FOR(j, 0, cnt[1] + 1) {
    if ((200 * i + 100 * j) * 2 == s) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
