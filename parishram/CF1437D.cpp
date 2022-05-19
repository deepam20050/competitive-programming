#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

queue < int > q;
int a[N], d[N];

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    a[n] = 1e9;
    while (!q.empty()) {
      q.pop();
    }
    q.emplace(1);
    d[1] = 0;
    for (int i = 1; i < n;) {
      int x = q.front();
      q.pop();
      int r = i + 1;
      q.emplace(a[i]);
      d[a[i]] = d[x] + 1;
      while (r < n && a[r - 1] < a[r]) {
        d[a[r]] = d[x] + 1;
        q.emplace(a[r]);
        ++r;
      }
      i = r;
    }
    printf("%d\n", *max_element(d + 1, d + n + 1));
  }
  return 0;
}
