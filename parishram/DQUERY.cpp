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

const int A = 1e6 + 5;
const int Q = 2e5 + 5;
const int N = 3e4 + 5;
const int SQN = 175;

struct query {
  int id, l, r, lb, rb;
} q[Q];

int cnt[A];
int a[N];
int ans = 0;
int res[Q];

void add_element (int idx) {
  ++cnt[a[idx]];
  ans += cnt[a[idx]] == 1;
}

void remove_element (int idx) {
  --cnt[a[idx]];
  ans -= cnt[a[idx]] == 0;
}

void test_case() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int nq; cin >> nq;
  for (int i = 0; i < nq; ++i) {
    int l, r; cin >> l >> r;
    q[i] = {i, l, r, l / SQN, r / SQN};
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
    res[q[i].id] = ans;
  }
  for (int i = 0; i < nq; ++i) {
    cout << res[i] << '\n';
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