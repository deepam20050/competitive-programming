#include "bits/stdc++.h"

using namespace std;

const int N = 2e5, M = 1e6 + 2;

bitset < M > vis;
int a[N], b[N], arr[N];
int go[M];

int main () {
  int n, x, y;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", a + i, b + i);
    vis[b[i]] = 1;
    go[a[i]] = b[i];
    if (a[i] == 0) {
      y = b[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[a[i]]) {
      x = a[i];
    }
  }
  for (int i = 0; i < n; i += 2) {
    arr[i] = x;
    x = go[x];
  }
  for (int i = 1; i < n; i += 2) {
    arr[i] = y;
    y = go[y];
  }
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
  return 0;
}
