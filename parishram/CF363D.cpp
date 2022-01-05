// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1e5 + 5;

int b[N], p[N];
lli rem;
int n, m, a;

bool f (int len) {
  rem = 0;
  lli sum = 0;
  int j = 0;
  FOR(i, 1, len + 1) {
    sum += p[i];
  }
  if (sum <= a) return 1;
  lli ac = a;
  rem = sum - a;
  int lft = n;
  for (int i = len; i >= 1; --i) {
    if (j < n) {
      if (b[j] >= p[i]) {
        ++j;
      } else if (b[j] + ac >= p[i]) {
        ac -= p[i] - b[j];
        ++j;
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  }
  return 1;
}

int main () {
  scanf("%d %d %d", &n, &m, &a);
  FOR(i, 0, n) scanf("%d", b + i);
  FOR(i, 1, m + 1) scanf("%d", p + i);
  sort(p + 1, p + m + 1);
  sort(b, b + n, greater < int > ());
  int l = 0, r = min(n, m) + 1;
  FOR(i, 0, 20) {
    int mid = l + r >> 1;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  f(l);
  printf("%d %lld\n", l, rem);
  return 0;
}
