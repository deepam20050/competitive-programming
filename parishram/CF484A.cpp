#include "bits/stdc++.h"

using namespace std;

int main () {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long l, r;
    scanf("%lld %lld", &l, &r);
    if (l == r) {
      printf("%lld\n", r);
      continue;
    }
    bool ok = 0;
    for (int i = 60; i >= 0; --i) {
      if ((r == (1LL << i) - 1)) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      printf("%lld\n", r);
      continue;
    }
    long long ans = 0;
    for (int i = 60; i >= 0; --i) {
      int bitr = (r >> i) & 1;
      int bitl = (l >> i) & 1;
      if (bitr && bitl) {
        ans |= 1LL << i;
      }
      if (bitr && !bitl) {
        if (r == (1LL << i + 1) - 1) {
          ans |= r;
        } else {
          ans |= (1LL << i) - 1;
        }
        break;
      }
      if (bitr) {
        r ^= 1LL << i;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
