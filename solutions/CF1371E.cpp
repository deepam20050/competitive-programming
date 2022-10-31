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

const int N = 2005;

int f[N];
int n, p;
int a[N];

int main () {
  scanf("%d %d", &n, &p);
  f[0] = 1;
  FOR(i, 1, N) {
    f[i] = f[i - 1] * i % p;
  }
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  vector < int > good;
  FOR(x, 1, N) {
    int curr = 0;
    bool ok = 1;
    FOR(j, 0, n) {
      if (!ok) break;
      while (curr < n && a[curr] <= x + j) {
        ++curr;
      }
      ok &= curr - j > 0 && p != curr - j;
    }
    if (ok) {
      good.eb(x);
    }
  }
  printf("%d\n", sz(good));
  for (auto &e : good) {
    printf("%d ", e);
  }
  return 0;
}
