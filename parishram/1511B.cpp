#include "bits/stdc++.h"

using namespace std;

using lli = long long;

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int a_ = a - c + 1;
    int b_ = b - c + 1;
    lli mult = 1;
    for (int i = 1; i < c; ++i) {
      mult *= 10ll;
    }
    lli x = 1, y = 2;
    lli pw10 = 10;
    for (int i = 1; i < a_; ++i) {
      x += 1 * pw10;
      pw10 *= 10;
    }
    pw10 = 10;
    for (int i = 1; i < b_; ++i) {
      y += 1 * pw10;
      pw10 *= 10;
    }
    printf("%lld %lld\n", x * mult, y * mult);
  }
  return 0;
}