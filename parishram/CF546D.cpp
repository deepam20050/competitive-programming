#include "bits/stdc++.h"

using namespace std;

const int N = 5e6 + 5;

bitset < N > v;
int sp[N];
int pref[N];

void pre_calc () {
  for (int i = 2; i < N; i += 2) {
    sp[i] = 2;
  }
  sp[1] = 1;
  for (int i = 3; i < N; i += 2) {
    if (!v[i]) {
      sp[i] = i;
      for (int j = 1; 1LL * j * i < N; j += 2) {
        if (!v[j * i]) {
          v[j * i] = 1;
          sp[j * i] = i;
        }
      }
    }
  }
}

int main () {
  pre_calc();
  for (int i = 2; i < N; ++i) {
    pref[i] = pref[i - 1];
    int x = i;
    while (x > 1) {
      ++pref[i];
      x /= sp[x];
    }
  }
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", pref[a] - pref[b]);
  }
  return 0;
}
