#include "bits/stdc++.h"

using namespace std;

using li = long long;

li n, k, dd1, dd2;

inline bool f () {
  if (n % 3) {
    return 0;
  }
  for (int sign1 = -1; sign1 <= 1; ++sign1) {
    for (int sign2 = -1; sign2 <= 1; ++sign2) {
      if (sign1 == 0 || sign2 == 0) continue;
      li d1 = sign1 * dd1, d2 = sign2 * dd2;
      if ((k - d1 + d2) % 3) continue;
      li x2 = (k - d1 + d2) / 3;
      if (x2 >= 0 && x2 <= k) {
        li x1 = x2 + d1, x3 = x2 - d2;
        li by3 = n / 3;
        if (x1 >= 0 && x1 <= k && x3 >= 0 && x3 <= k && x1 <= by3 && x2 <= by3 && x3 <= by3) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%lld %lld %lld %lld", &n, &k, &dd1, &dd2);
    f() ? puts("yes") : puts("no");
  }
  return 0;
}
