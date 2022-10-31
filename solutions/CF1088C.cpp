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
  FOR(i, 0, n) {
    int x; scanf("%d", &x);
    v[i] = x;
  }
  printf("%d\n", n + 1);
  int add = 0;
  for (int i = n - 1; i >= 0; --i) {
    int x = (i - (v[i] + add) % n + n) % n;
    printf("1 %d %d\n", i + 1, x);
    add += x;
  }
  printf("2 %d %d\n", n, n);
  return 0;
}
