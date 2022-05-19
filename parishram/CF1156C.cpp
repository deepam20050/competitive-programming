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

const int N = 2e5 + 5;

int a[N];
int n, m;
int z;

inline bool f (int m) {
  FOR(i, 0, m) {
    if (a[n - m + i] - a[i] < z) {
      return 0;
    }
  }
  return 1;
}

int main () {
  scanf("%d %d", &n, &z);
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  int l = 0, r = n / 2 + 1;
  FOR(i, 0, 30) {
    int m = l + r >> 1;
    if (f(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  printf("%d\n", l);
  return 0;
}
