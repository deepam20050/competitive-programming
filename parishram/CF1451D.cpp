#include "bits/stdc++.h"

using namespace std;

long long sqr (long long x) {
  return x * x;
}

const double sqrt2 = 1.41421356237;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    long long d, k;
    scanf("%lld %lld", &d, &k);
    long long kz = d / sqrt2;
    kz = k * (kz / k);
    if (sqr(kz + k) + sqr(kz) > sqr(d)) {
      puts("Utkarsh");
    } else {
      puts("Ashish");
    }
  }
  return 0;
}
