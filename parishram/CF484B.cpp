#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 1;

int mx[N + N];
bitset < N > vis;

int main () {
  int n;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    mx[x] = x;
    vis[x] = 1;
  }
  for (int i = 1; i < N + N; ++i) {
    mx[i] = max(mx[i - 1], mx[i]);
  }
  int ans = 0;
  for (int i = 2; i < N; ++i) {
    if (!vis[i]) continue;
    for (int j = i + i - 1; j < N + N; j += i) {
      ans = max(ans, mx[j] % i);
    }
  }
  printf("%d\n", ans);
  return 0;
}
