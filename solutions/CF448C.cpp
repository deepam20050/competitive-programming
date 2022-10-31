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

const int N = 5005;

int a[N];
int n;

int solve (int l, int r, int height) {
  if (l > r) return 0;
  int mn = *min_element(a + l, a + r + 1);
  int ret = 0;
  int lst = l;
  FOR(i, l, r + 1) {
    if (a[i] == mn) {
      ret += solve(lst, i - 1, mn);
      lst = i + 1;
    }
  }
  ret += solve(lst, r, mn);
  ret += mn - height;
  return min(r - l + 1, ret);
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", a + i);
  printf("%d\n", solve(1, n, 0));
  return 0;
}
