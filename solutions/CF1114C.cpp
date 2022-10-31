#include "bits/stdc++.h"

using namespace std;

const long long LIMIT = 1e9;

int main () {
  long long n, b;
  scanf("%lld %lld", &n, &b);
  long long ans = 1LL << 60;
  for (long long i = 2; i * i <= b; ++i) {
    int cnt = 0;
    while (b % i == 0) {
      b /= i;
      ++cnt;
    }
    if (cnt) {
      long long prod = 1;
      long long cnt2 = 0;
      while (prod <= n / i) {
        prod *= i;
        cnt2 += n / prod;
      }
      ans = min(ans, cnt2/cnt);
    }
  }
  if (b > 1) {
    long long prod = 1;
    long long cnt2 = 0;
    while (prod <= n / b) {
      prod *= b;
      cnt2 += n / prod;
    }
    ans = min(ans, cnt2);
  }
  (ans == 1LL << 60) ? puts("0") : printf("%lld", ans);
  return 0;
}
