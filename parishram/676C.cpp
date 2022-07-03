#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

char str[N];
int pos[2][N], suff[2][N];
int n, k;

int get (int d, int i) {
  int ret = -1;
  if (suff[d ^ 1][i] <= k) {
    ret = max(ret, n - i + 1);
  } else {
    int x = pos[d ^ 1][suff[d ^ 1][i] - k];
    if (x == -1) {
      x = n + 1;
    }
    ret = max(ret, x - i - 1);
  }
  return ret;
}

int main () {
  scanf("%d %d", &n, &k);
  scanf("%s", str + 1);
  int ans = 0;
  memset(pos, -1, sizeof pos);
  for (int i = n; i >= 1; --i) {
    int d = str[i] - 'a';
    suff[d][i] = suff[d][i + 1] + 1;
    suff[d ^ 1][i] = suff[d ^ 1][i + 1];
    pos[d][suff[d][i]] = i + 1;
    ans = max(ans, get(0, i));
    ans = max(ans, get(1, i));
  }
  printf("%d\n", ans);
  return 0;
}