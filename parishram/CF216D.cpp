#include "bits/stdc++.h"

using namespace std;

const int N = 1e3 + 5;

vector < int > points[N];
int n;

int get (int i, int l, int r) {
  return upper_bound(points[i].begin(), points[i].end(), r) - lower_bound(points[i].begin(), points[i].end(), l);
}

int main () {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int k;
    scanf("%d", &k);
    for (int j = 0, x; j < k; ++j) {
      scanf("%d", &x);
      points[i].emplace_back(x);
    }
    sort(points[i].begin(), points[i].end());
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i == 0 ? n - 1 : i - 1);
    int k = (i == n - 1 ? 0 : i + 1);
    for (int w = 1; w < points[i].size(); ++w) {
      int l = points[i][w - 1];
      int r = points[i][w];
      int prev = get(j, l, r);
      int nxt = get(k, l, r);
      ans += prev != nxt;
    }
  }
  printf("%d\n", ans);
  return 0;
}
