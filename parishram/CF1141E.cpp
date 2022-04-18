#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

int d[N];

int main () {
  long long H, S = 0, s = 0;
  int n;
  scanf("%lld %d", &H, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", d + i);
    S += 1LL * d[i];
    if (H + S <= 0) {
      printf("%d\n", i);
      return 0;
    }
  }
  long long ans = 1e18;
  for (int i = 1; i <= n; ++i) {
    s += 1LL * d[i];
    if (S == 0) {
      if (s + H == 0) {
        ans = i;
        break;
      }
      continue;
    }
    long long k = -(s + H) / S + (-(s + H) % S != 0);
    if (k < 0) {
      continue;
    }
    if (H + S * k + s <= 0) {
      ans = min(ans, n * k + i);
    }
  }
  ans == (long long)1e18 ? puts("-1") : printf("%lld\n", ans);
  return 0;
}
