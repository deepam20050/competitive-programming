#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

int a[N + N], straws[N + N], blues[N + N];
vector < pair < int, int > > x_y, y_x;

void solve () {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n + n; ++i) {
    scanf("%d", a + i);
    straws[i] = (a[i] == 1) + straws[i - 1];
    blues[i] = (a[i] == 2) + blues[i - 1];
  }
  int eqs = n + n;
  x_y.clear();
  y_x.clear();
  for (int i = n + n, x = 0, y = 0; i > n; --i) {
    x += a[i] == 1;
    y += a[i] == 2;
    if (x == y) {
      eqs = i - 1;
    } else if (x > y) {
      x_y.emplace_back(x - y, i - 1);
    } else if (y > x) {
      y_x.emplace_back(y - x, i - 1);
    }
  }
  sort(x_y.begin(), x_y.end());
  sort(y_x.begin(), y_x.end());
  int ans = n + n;
  for (int i = n; i >= 0; --i) {
    int x = straws[i];
    int y = blues[i];
    if (x == y) {
      ans = min(ans, n - i + eqs - n);
    } else if (x > y) {
      int req = x - y;
      int pos = lower_bound(y_x.begin(), y_x.end(), make_pair(x - y, -1)) - y_x.begin();
      if (pos < y_x.size() && y_x[pos].first == x - y) {
        ans = min(ans, n - i + y_x[pos].second - n);
      }
    } else if (y > x) {
      int req = y - x;
      int pos = lower_bound(x_y.begin(), x_y.end(), make_pair(y - x, -1)) - x_y.begin();
      if (pos < x_y.size() && x_y[pos].first == y - x) {
        ans = min(ans, n - i + x_y[pos].second - n);
      }
    }
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
