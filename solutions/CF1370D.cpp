// AC
#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

int a[N];
int n, k;

bool f (int x, int curr) {
  int len = 0;
  for (int i = 1; i <= n; ++i) {
    if (!curr) {
      curr ^= 1;
      ++len;
    } else {
      if (a[i] <= x) {
        ++len;
        curr ^= 1;
      }
    }
  }
  return len >= k;
}

int main () {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  int l = 0, r = 1e9;
  for (int i = 0; i < 30; ++i) {
    int m = l + r >> 1;
    if (f(m, 0) || f(m, 1)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  printf("%d\n", l);
  return 0;
}