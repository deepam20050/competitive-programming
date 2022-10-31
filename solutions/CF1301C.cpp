#include "bits/stdc++.h"

using namespace std;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long g = m + 1;
    long long k = (n - m) / g;
    printf("%lld\n", n * (n + 1) / 2 - k * (k + 1) / 2 * g - (k + 1) * ((n - m) % g));
  }
  return 0;
}
