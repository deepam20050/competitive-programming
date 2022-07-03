#include "bits/stdc++.h"
using namespace std;

#ifdef DEBUG
  #include "../algo/debug.hpp"
#else
  #define debug(...)
#endif
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

const int N = 3e5 + 5;
const int SQN = 550;

struct query {
  int id, l, r, k, lb;
} q[N];

int a[N];
set < int > best[N];
int cnt[N];
int ans[N];

void add_element (int idx) {
  idx = a[idx];
  ++cnt[idx];
  best[cnt[idx]].emplace(idx);
}

void remove_element (int idx) {
  idx = a[idx];
  best[cnt[idx]].erase(idx);
  --cnt[idx];
}

inline int get (int a, int b) {
  return a / b + 1;
}

void test_case() {
  int n, nq; cin >> n >> nq;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < nq; ++i) {
    int l, r, k; cin >> l >> r >> k;
    q[i] = {i, l, r, k, l / SQN};
  }
  sort(q, q + nq, [&] (const query &a, const query &b) {
    if (a.lb != b.lb) return a.lb < b.lb;
    return a.lb & 1 ? a.r < b.r : a.r > b.r;
  });
  for (int i = 0, L = 1, R = 0; i < nq; ++i) {
    while (R < q[i].r) add_element(++R);
    while (L > q[i].l) add_element(--L);
    while (R > q[i].r) remove_element(R--);
    while (L < q[i].l) remove_element(L++);
    int what = get(q[i].r - q[i].l + 1, q[i].k);
    ans[q[i].id] = best[what].empty() ? -1 : *best[what].begin();
  }
  for (int i = 0; i < nq; ++i) {
    cout << ans[i] << '\n';
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  #ifdef DEBUG
    freopen("debug.txt", "w", stderr);
  #endif
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}