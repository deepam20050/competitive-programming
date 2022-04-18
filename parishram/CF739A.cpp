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
  int n, m;
  scanf("%d %d", &n, &m);
  int len = n + 1;
  FOR(i, 0, m) {
    int l, r;
    scanf("%d %d", &l, &r);
    len = min(len, r - l + 1);
  }
  printf("%d\n", len);
  FOR(i, 0, n) {
    printf("%d ", i % len);
  }
  return 0;
}
