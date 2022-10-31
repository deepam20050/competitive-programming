#include "bits/stdc++.h"

using namespace std;

const int N = 3e5 + 5;

int a[N], bad;
int n;

int f (int i) { 
  if (i == 1 || i == n) {
    return 0;
  }
  return (a[i] > a[i + 1] && a[i] > a[i - 1]) || (a[i] < a[i + 1] && a[i] < a[i - 1]);
}

int check (int i, int x) {
  int curr = bad;
  curr -= f(i) + f(i + 1) + f(i - 1);
  int prv = a[i];
  a[i] = x;
  curr += f(i) + f(i + 1) + f(i - 1);
  a[i] = prv;
  return curr;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    bad = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
    }
    for (int i = 2; i <= n - 1; ++i) {
      bad += f(i);
    }
    int ans = min(bad - f(2), bad - f(n - 1));
    for (int i = 2; i <= n - 1; ++i) {
      int l = a[i - 1], r = a[i + 1], y = a[i];
      int x1 = check(i, l);
      int x2 = check(i, r);
      int x3 = check(i, l + 1);
      int x4 = check(i, r + 1);
      ans = min(ans, min(x1, min(x2, min(x3, x4))));
      a[i] = y;
    }
    printf("%d\n", ans < 0 ? 0 : ans);
  }
  return 0;
}
