#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;
const int LN = 2e6 + 2;

struct Query {
  int idx, l, r, lb;
} q[N];

int arr[N], pref[N];
int cnt[LN];
long long print[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
  }
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i - 1] ^ arr[i];
  }
  const int block = max(1, (int)pow(n, 1.0 / 2.0));
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    q[i] = {i, x, y, x / block};
  }
  sort(q, q + m, [&] (const Query &a, const Query &b) {
    if (a.lb != b.lb) return a.lb < b.lb;
    return (a.lb & 1) ? a.r < b.r : a.r > b.r;
  });
  long long ans = 0;
  cnt[0] = 1;
  for (int i = 0, l = 1, r = 0; i < m; ++i) {
    while (r < q[i].r) {
      ++r;
      int s = pref[r];
      ans += 1LL * cnt[s ^ k];
      ++cnt[s];
    }
    bool done2 = 0;
    while (l > q[i].l) {
      if (!done2) {
        --cnt[pref[l - 1]];
        done2 = 1;
      }
      --l;
      int s = pref[l - 1];
      ++cnt[pref[l]];
      ans += 1LL * cnt[s ^ k];
      if (l == q[i].l) {
        ++cnt[pref[l - 1]];
      }
    }
    while (r > q[i].r) {
      int s = pref[r];
      --cnt[s];
      ans -= 1LL * cnt[s ^ k];
      --r;
    }
    bool done = 0;
    while (l < q[i].l) {
      if (!done) {
        done = 1;
        --cnt[pref[l - 1]];
      }
      int s = pref[l - 1];
      ans -= 1LL * cnt[s ^ k];
      --cnt[pref[l]];
      ++l;
      if (l == q[i].l) {
        ++cnt[pref[l - 1]];
      }
    }
    print[q[i].idx] = ans;
  }
  for (int i = 0; i < m; ++i) {
    printf("%lld\n", print[i]);
  }
  return 0;
}
