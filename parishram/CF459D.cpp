#include "bits/stdc++.h"

using namespace std;

const int N = 1e6 + 5;

int arr[N];
unordered_map < int , int > cnt_pref, cnt_suff;

struct FenwickTree {
  int val[N] = {0};
  void update (int idx, int n, int add) {
    if (idx == 0) {
      return;
    }
    while (idx <= n) {
      val[idx] += add;
      idx += idx & -idx;
    }
  }
  int query (int idx) {
    int ret = 0;
    while (idx) {
      ret += val[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
} tree;

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    ++cnt_pref[arr[i]];
  }
  long long ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    ans += tree.query(cnt_pref[arr[i]] - 1);
    --cnt_pref[arr[i]];
    ++cnt_suff[arr[i]];
    tree.update(cnt_suff[arr[i]], n, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
