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

const int N = 1e5 + 5;

int nxt[N];
int pos[N];
int a[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  FOR(i, 0, n + 1) {
    pos[i] = n + 1;
  }
  for (int i = n; i >= 0; --i) {
    nxt[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  int x = 0, y = 0, res = 0;
  FOR(i, 1, n + 1) {
    if (a[x] == a[i]) {
      res += a[y] != a[i];
      y = i;
    } else if (a[y] == a[i]) {
      res += a[x] != a[i];
      x = i;
    } else {
      if (nxt[x] < nxt[y]) {
        res += a[x] != a[i];
        x = i;
      } else {
        res += a[y] != a[i];
        y = i;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}
