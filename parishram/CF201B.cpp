#include "bits/stdc++.h"

using namespace std;

long long sq (int x) {
  return 1ll * x * x;
}

int main () {
  int n, m;
  scanf("%d %d", &n, &m);
  auto s1 = 0ll;
  auto s2 = 0ll;
  auto s3 = 0ll;
  auto s4 = 0ll;
  auto s5 = 0ll;
  for (int x = 1; x <= n; ++x) {
    for (int y = 1, c; y <= m; ++y) {
      scanf("%d", &c);
      s1 += 16ll * c * (sq(x) + sq(y));
      s2 += 8ll * c;
      s3 += 16ll * c * (x + y);
      s4 += 32ll * c * x;
      s5 += 32ll * c * y;
    }
  }
  int ans_a, ans_b;
  long long ans = 9e18;
  for (int a = 0; a <= n; ++a) {
    for (int b = 0; b <= m; ++b) {
      auto req = s1 + 2ll * s2 * (sq(a) + sq(b)) + s2 - s3 + 2ll * s2 * (a + b) - s4 * a - s5 * b;
      if (req < ans) {
        ans = req;
        ans_a = a;
        ans_b = b;
      }
    }
  }
  printf("%lld\n%d %d", ans, ans_a, ans_b);
  return 0;
}
