#include "bits/stdc++.h"

using namespace std;

const int N = 5000;

int dp[N], nxt[N];
pair < int, pair < int, int > > p[N];

int main () {
  int n, w, h;
  scanf("%d %d %d", &n, &w, &h);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &p[i].first, &p[i].second.first);
    p[i].second.second = i;
  }
  sort(p, p + n);
  int ans = 0;
  int fst = -1;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = 1;
    nxt[i] = i;
    for (int j = i + 1; j < n; ++j) {
      if (p[j].first > p[i].first && p[j].second.first > p[i].second.first) {
        if (1 + dp[j] > dp[i]) {
          nxt[i] = j;
          dp[i] = 1 + dp[j];
        }
      }
    }
    if (p[i].first > w && p[i].second.first > h) {
      if (dp[i] >= ans) {
        ans = dp[i];
        fst = i;
      }
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < ans; ++i) {
    printf("%d ", p[fst].second.second + 1);
    fst = nxt[fst];
  }
  return 0;
}
