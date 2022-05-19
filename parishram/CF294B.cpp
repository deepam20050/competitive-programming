#include "bits/stdc++.h"

using namespace std;

vector < int > a[2];

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    a[x].emplace_back(y);
  }
  sort(a[0].begin(), a[0].end());
  sort(a[1].begin(), a[1].end());
  int ans = 1e9;
  for (int i = 0; i <= a[0].size(); ++i) {
    for (int j = 0; j <= a[1].size(); ++j) {
      int s = 0;
      for (int k = 0; k < a[0].size() - i; ++k) {
        s += a[0][k];
      }
      for (int k = 0; k < a[1].size() - j; ++k) {
        s += a[1][k];
      }
      if (s <= i + j + j) {
        ans = min(ans, i + j + j);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
