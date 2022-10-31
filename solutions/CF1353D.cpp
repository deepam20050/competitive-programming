#include "bits/stdc++.h"

using namespace std;

using pi = pair < int, pair < int, int > >;

const int N = 2e5 + 5;

int arr[N];
priority_queue < pi > q;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    q.push({n, {-1, n}});
    int curr = 1;
    while (!q.empty()) {
      auto top = q.top();
      q.pop();
      int l = -top.second.first, r = top.second.second;
      int mid = l + r >> 1;
      arr[mid] = curr++;
      if (l <= mid - 1) {
        q.push({mid - l, {-l, mid - 1}});
      } 
      if (r >= mid + 1) {
        q.push({r - mid, {-mid - 1, r}});
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", arr[i]);
    }
    puts("");
  }
  return 0;
}
