#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  long long ans = 0;
  for (int mx = 0; mx < 31; ++mx) {
    long long curr = 0;
    long long rem = 0;
    for (int i = 0; i < n; ++i) {
      curr += (a[i] > mx ? -1e9 : a[i]);
      rem = min(rem, curr);
      ans = max(ans, curr - rem - mx);
    }
  }
  printf("%lld", ans);
  return 0;
}
