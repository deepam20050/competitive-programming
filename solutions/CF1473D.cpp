#include "bits/stdc++.h"

using namespace std;

const int N = 2e5 + 5;

char str[N];
int until_min[N];
int until_max[N];
int from_max[N];
int from_min[N];
int sum[N];

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    sum[0] = 0;
    until_min[0] = 0;
    until_max[0] = 0;
    from_min[n + 1] = 0;
    from_max[n + 1]= 0;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i - 1] + (str[i - 1] == '+' ? 1 : -1);
      until_min[i] = min(sum[i], until_min[i - 1]);
      until_max[i] = max(sum[i], until_max[i - 1]);
    }
    int curr = 0;
    for (int i = n; i >= 1; --i) {
      curr = (str[i - 1] == '+' ? 1 : -1);
      from_min[i] = min(from_min[i + 1] + curr, 0);
      from_max[i] = max(from_max[i + 1] + curr, 0);
    }
    while (m--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int add = sum[l - 1];
      int L = min(until_min[l - 1], add + from_min[r + 1]);
      int R = max(until_max[l - 1], add + from_max[r + 1]);
      printf("%d\n", R - L + 1);
    }
  }
  return 0;
}
