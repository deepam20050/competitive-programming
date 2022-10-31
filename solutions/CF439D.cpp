#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

int a[N], b[N];
int n, m;

int main () {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", a + i);
  for (int i = 0; i < m; ++i) scanf("%d", b + i);
  sort(a, a + n);
  sort(b, b + m, greater < int > ());
  long long ans = 0;
  for (int i = 0; i < n && b[i] > a[i]; ++i) {
    ans += abs(a[i] - b[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
